#include "Types_lalr.h"

#include "Types_y.h"

typedef enum {
  Types_NONSENSE,
  hashincludespacelessthanstdargdothgreaterthansym_value,
  hashincludespacelessthanstddefdothgreaterthansym_value,
  hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym_value,
  hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym_value,
  hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym_value,
  hashincludespacelessthanfrontslashSymTabdothgreaterthansym_value,
  hashincludespacebackslashdoublequotesym_value,
  Identsym_value,
  underscoredefsdothbackslashdoublequotesym_value,
  typedefsym_value,
  enumsym_value,
  openchainsym_value,
  closechainsym_value,
  semicolonsym_value,
  externspacecharspacestarsym_value,
  underscorenamesopenbrkclosebrksemicolonsym_value,
  hashdefinespaceNUMunderscoresym_value,
  Intsym_value,
  typedefspaceBindspaceBindunderscoresym_value,
  typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym_value,
  hashdefinespaceListunderscoreBindunderscoresym_value,
  underscoredataopenparxcloseparsym_value,
  openparBindunderscoresym_value,
  closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym_value,
  underscorenextopenparxcloseparsym_value,
  openparListunderscoreBindunderscoresym_value,
  closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym_value,
  hashdefinespaceBindunderscoresym_value,
  _kindsym_value,
  hashifndefspaceDEFunderscoreTYPEunderscoresym_value,
  hashdefinespaceDEFunderscoreTYPEunderscoresym_value,
  typedefspacestructspacesunderscoresym_value,
  starsym_value,
  hashendifsym_value,
  typedefspacesym_value,
  externsym_value,
  underscorerootsemicolonsym_value,
  hashifndefspaceDEFunderscoreSTRUCTunderscoresym_value,
  hashdefinespaceDEFunderscoreSTRUCTunderscoresym_value,
  hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym_value,
  spacestarslashsym_value,
  structsym_value,
  s_sym_value,
  unionspaceopenchainsym_value,
  closechainspacesubsemicolonsym_value,
  hashdefinesym_value,
  _sym_value,
  openparunderscorepcloseparsym_value,
  openparsym_value,
  openparstarunderscorepcloseparsym_value,
  dotsym_value,
  closeparsym_value,
  underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym_value,
  CREATEsym_value,
  underscoreparsedothbackslashdoublequotesym_value,
  dothbackslashdoublequotesym_value,
  commasym_value,
  _USER_FIELDSsym_value,
  dotsubdotsym_value,
  hole_OPTMORE_EnumType_value,
  hole_OPTMORE_PointerType_value,
  hole_OPTMORE_subtypedef_value,
  hole_includes2_value,
  hole_OPTMORE_BindType_value,
  hole_OPTMORE_StructType_value,
  hole_Types_value,
  hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value,
  hole_Enums_value,
  hole_EnumType_value,
  hole_ALT_TypeName_SEP_commasym_NL_value,
  hole_BindType_value,
  hole_PointerType_value,
  hole_subtypedef_value,
  hole_struct_type_value,
  hole_OPTMORE_macro_value,
  hole_OPTMORE_CreateFunction_value,
  hole_StructType_value,
  hole_OPTMORE_field_value,
  hole_OPTMORE_struct_type_value,
  hole_sub_union_value,
  hole_OPTMORE_dotsubdotsym_Identsym_value,
  hole_macro_value,
  hole_TypeNames_value,
  hole_field_value,
  hole_TypeName_value,
  hole_CreateFunction_value,
  hole_ALT_TypeName_SEP__sym_value,
  Types_EOF_value,
  includes1_value,
  OPTMORE_EnumType_value,
  OPTMORE_PointerType_value,
  OPTMORE_subtypedef_value,
  includes2_value,
  OPTMORE_BindType_value,
  RootDecl_value,
  OPTMORE_StructType_value,
  Types_value,
  OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_value,
  OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value,
  Enums_value,
  EnumType_value,
  ALT_TypeName_SEP_commasym_NL_value,
  BindType_value,
  PointerType_value,
  subtypedef_value,
  struct_type_value,
  OPTMORE_macro_value,
  OPTMORE_CreateFunction_value,
  StructType_value,
  OPT_Identsym__USER_FIELDSsym_value,
  OPTMORE_field_value,
  OPT_sub_union_value,
  OPT_Identsym_value,
  OPTMORE_struct_type_value,
  sub_union_value,
  OPTMORE_dotsubdotsym_Identsym_value,
  macro_value,
  TypeNames_value,
  field_value,
  TypeName_value,
  CreateFunction_value,
  ALT_TypeName_SEP__sym_value,
  Types_ERROR
} TypesSymbol;

static TypesSymbol _Types_token;

static TypesSymbol _Types_symbol;

#define NUM_TERMINALS 89

#define WORDS_IN_SET ((NUM_TERMINALS+BITSPERWORD-1)/BITSPERWORD)

static String Types_symbol_names[] = {
  "Types_NONSENSE",
  "hashincludespacelessthanstdargdothgreaterthansym",
  "hashincludespacelessthanstddefdothgreaterthansym",
  "hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym",
  "hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym",
  "hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym",
  "hashincludespacelessthanfrontslashSymTabdothgreaterthansym",
  "hashincludespacebackslashdoublequotesym",
  "Identsym",
  "underscoredefsdothbackslashdoublequotesym",
  "typedefsym",
  "enumsym",
  "openchainsym",
  "closechainsym",
  "semicolonsym",
  "externspacecharspacestarsym",
  "underscorenamesopenbrkclosebrksemicolonsym",
  "hashdefinespaceNUMunderscoresym",
  "Intsym",
  "typedefspaceBindspaceBindunderscoresym",
  "typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym",
  "hashdefinespaceListunderscoreBindunderscoresym",
  "underscoredataopenparxcloseparsym",
  "openparBindunderscoresym",
  "closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym",
  "underscorenextopenparxcloseparsym",
  "openparListunderscoreBindunderscoresym",
  "closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym",
  "hashdefinespaceBindunderscoresym",
  "_kindsym",
  "hashifndefspaceDEFunderscoreTYPEunderscoresym",
  "hashdefinespaceDEFunderscoreTYPEunderscoresym",
  "typedefspacestructspacesunderscoresym",
  "starsym",
  "hashendifsym",
  "typedefspacesym",
  "externsym",
  "underscorerootsemicolonsym",
  "hashifndefspaceDEFunderscoreSTRUCTunderscoresym",
  "hashdefinespaceDEFunderscoreSTRUCTunderscoresym",
  "hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym",
  "spacestarslashsym",
  "structsym",
  "s_sym",
  "unionspaceopenchainsym",
  "closechainspacesubsemicolonsym",
  "hashdefinesym",
  "_sym",
  "openparunderscorepcloseparsym",
  "openparsym",
  "openparstarunderscorepcloseparsym",
  "dotsym",
  "closeparsym",
  "underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym",
  "CREATEsym",
  "underscoreparsedothbackslashdoublequotesym",
  "dothbackslashdoublequotesym",
  "commasym",
  "_USER_FIELDSsym",
  "dotsubdotsym",
  "hole_OPTMORE_EnumType",
  "hole_OPTMORE_PointerType",
  "hole_OPTMORE_subtypedef",
  "hole_includes2",
  "hole_OPTMORE_BindType",
  "hole_OPTMORE_StructType",
  "hole_Types",
  "hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym",
  "hole_Enums",
  "hole_EnumType",
  "hole_ALT_TypeName_SEP_commasym_NL",
  "hole_BindType",
  "hole_PointerType",
  "hole_subtypedef",
  "hole_struct_type",
  "hole_OPTMORE_macro",
  "hole_OPTMORE_CreateFunction",
  "hole_StructType",
  "hole_OPTMORE_field",
  "hole_OPTMORE_struct_type",
  "hole_sub_union",
  "hole_OPTMORE_dotsubdotsym_Identsym",
  "hole_macro",
  "hole_TypeNames",
  "hole_field",
  "hole_TypeName",
  "hole_CreateFunction",
  "hole_ALT_TypeName_SEP__sym",
  "Types_EOF",
  "includes1",
  "OPTMORE_EnumType",
  "OPTMORE_PointerType",
  "OPTMORE_subtypedef",
  "includes2",
  "OPTMORE_BindType",
  "RootDecl",
  "OPTMORE_StructType",
  "Types",
  "OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym",
  "OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym",
  "Enums",
  "EnumType",
  "ALT_TypeName_SEP_commasym_NL",
  "BindType",
  "PointerType",
  "subtypedef",
  "struct_type",
  "OPTMORE_macro",
  "OPTMORE_CreateFunction",
  "StructType",
  "OPT_Identsym__USER_FIELDSsym",
  "OPTMORE_field",
  "OPT_sub_union",
  "OPT_Identsym",
  "OPTMORE_struct_type",
  "sub_union",
  "OPTMORE_dotsubdotsym_Identsym",
  "macro",
  "TypeNames",
  "field",
  "TypeName",
  "CreateFunction",
  "ALT_TypeName_SEP__sym",
  "Types_ERROR"
};

static TypesSymbol Types_terminal_map[2*Types_ERROR];

static void fill_terminal_map (void)
{
  static Bool done = FALSE;
  if (done) return;
  done = TRUE;
  Types_terminal_map[0] = Types_NONSENSE;
  Types_terminal_map[hashincludespacelessthanstdargdothgreaterthansym-NONSENSE] = hashincludespacelessthanstdargdothgreaterthansym_value;
  Types_terminal_map[hashincludespacelessthanstddefdothgreaterthansym-NONSENSE] = hashincludespacelessthanstddefdothgreaterthansym_value;
  Types_terminal_map[hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym-NONSENSE] = hashincludespacelessthanfrontslashbasicunderscoretypesdothgreaterthansym_value;
  Types_terminal_map[hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym-NONSENSE] = hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym_value;
  Types_terminal_map[hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym-NONSENSE] = hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym_value;
  Types_terminal_map[hashincludespacelessthanfrontslashSymTabdothgreaterthansym-NONSENSE] = hashincludespacelessthanfrontslashSymTabdothgreaterthansym_value;
  Types_terminal_map[hashincludespacebackslashdoublequotesym-NONSENSE] = hashincludespacebackslashdoublequotesym_value;
  Types_terminal_map[Identsym-NONSENSE] = Identsym_value;
  Types_terminal_map[underscoredefsdothbackslashdoublequotesym-NONSENSE] = underscoredefsdothbackslashdoublequotesym_value;
  Types_terminal_map[typedefsym-NONSENSE] = typedefsym_value;
  Types_terminal_map[enumsym-NONSENSE] = enumsym_value;
  Types_terminal_map[openchainsym-NONSENSE] = openchainsym_value;
  Types_terminal_map[closechainsym-NONSENSE] = closechainsym_value;
  Types_terminal_map[semicolonsym-NONSENSE] = semicolonsym_value;
  Types_terminal_map[externspacecharspacestarsym-NONSENSE] = externspacecharspacestarsym_value;
  Types_terminal_map[underscorenamesopenbrkclosebrksemicolonsym-NONSENSE] = underscorenamesopenbrkclosebrksemicolonsym_value;
  Types_terminal_map[hashdefinespaceNUMunderscoresym-NONSENSE] = hashdefinespaceNUMunderscoresym_value;
  Types_terminal_map[Intsym-NONSENSE] = Intsym_value;
  Types_terminal_map[typedefspaceBindspaceBindunderscoresym-NONSENSE] = typedefspaceBindspaceBindunderscoresym_value;
  Types_terminal_map[typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym-NONSENSE] = typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym_value;
  Types_terminal_map[hashdefinespaceListunderscoreBindunderscoresym-NONSENSE] = hashdefinespaceListunderscoreBindunderscoresym_value;
  Types_terminal_map[underscoredataopenparxcloseparsym-NONSENSE] = underscoredataopenparxcloseparsym_value;
  Types_terminal_map[openparBindunderscoresym-NONSENSE] = openparBindunderscoresym_value;
  Types_terminal_map[closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym-NONSENSE] = closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym_value;
  Types_terminal_map[underscorenextopenparxcloseparsym-NONSENSE] = underscorenextopenparxcloseparsym_value;
  Types_terminal_map[openparListunderscoreBindunderscoresym-NONSENSE] = openparListunderscoreBindunderscoresym_value;
  Types_terminal_map[closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym-NONSENSE] = closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym_value;
  Types_terminal_map[hashdefinespaceBindunderscoresym-NONSENSE] = hashdefinespaceBindunderscoresym_value;
  Types_terminal_map[_kindsym-NONSENSE] = _kindsym_value;
  Types_terminal_map[hashifndefspaceDEFunderscoreTYPEunderscoresym-NONSENSE] = hashifndefspaceDEFunderscoreTYPEunderscoresym_value;
  Types_terminal_map[hashdefinespaceDEFunderscoreTYPEunderscoresym-NONSENSE] = hashdefinespaceDEFunderscoreTYPEunderscoresym_value;
  Types_terminal_map[typedefspacestructspacesunderscoresym-NONSENSE] = typedefspacestructspacesunderscoresym_value;
  Types_terminal_map[starsym-NONSENSE] = starsym_value;
  Types_terminal_map[hashendifsym-NONSENSE] = hashendifsym_value;
  Types_terminal_map[typedefspacesym-NONSENSE] = typedefspacesym_value;
  Types_terminal_map[externsym-NONSENSE] = externsym_value;
  Types_terminal_map[underscorerootsemicolonsym-NONSENSE] = underscorerootsemicolonsym_value;
  Types_terminal_map[hashifndefspaceDEFunderscoreSTRUCTunderscoresym-NONSENSE] = hashifndefspaceDEFunderscoreSTRUCTunderscoresym_value;
  Types_terminal_map[hashdefinespaceDEFunderscoreSTRUCTunderscoresym-NONSENSE] = hashdefinespaceDEFunderscoreSTRUCTunderscoresym_value;
  Types_terminal_map[hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym-NONSENSE] = hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym_value;
  Types_terminal_map[spacestarslashsym-NONSENSE] = spacestarslashsym_value;
  Types_terminal_map[structsym-NONSENSE] = structsym_value;
  Types_terminal_map[s_sym-NONSENSE] = s_sym_value;
  Types_terminal_map[unionspaceopenchainsym-NONSENSE] = unionspaceopenchainsym_value;
  Types_terminal_map[closechainspacesubsemicolonsym-NONSENSE] = closechainspacesubsemicolonsym_value;
  Types_terminal_map[hashdefinesym-NONSENSE] = hashdefinesym_value;
  Types_terminal_map[_sym-NONSENSE] = _sym_value;
  Types_terminal_map[openparunderscorepcloseparsym-NONSENSE] = openparunderscorepcloseparsym_value;
  Types_terminal_map[openparsym-NONSENSE] = openparsym_value;
  Types_terminal_map[openparstarunderscorepcloseparsym-NONSENSE] = openparstarunderscorepcloseparsym_value;
  Types_terminal_map[dotsym-NONSENSE] = dotsym_value;
  Types_terminal_map[closeparsym-NONSENSE] = closeparsym_value;
  Types_terminal_map[underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym-NONSENSE] = underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym_value;
  Types_terminal_map[CREATEsym-NONSENSE] = CREATEsym_value;
  Types_terminal_map[underscoreparsedothbackslashdoublequotesym-NONSENSE] = underscoreparsedothbackslashdoublequotesym_value;
  Types_terminal_map[dothbackslashdoublequotesym-NONSENSE] = dothbackslashdoublequotesym_value;
  Types_terminal_map[commasym-NONSENSE] = commasym_value;
  Types_terminal_map[_USER_FIELDSsym-NONSENSE] = _USER_FIELDSsym_value;
  Types_terminal_map[dotsubdotsym-NONSENSE] = dotsubdotsym_value;
  Types_terminal_map[hole_OPTMORE_EnumType-NONSENSE] = hole_OPTMORE_EnumType_value;
  Types_terminal_map[hole_OPTMORE_PointerType-NONSENSE] = hole_OPTMORE_PointerType_value;
  Types_terminal_map[hole_OPTMORE_subtypedef-NONSENSE] = hole_OPTMORE_subtypedef_value;
  Types_terminal_map[hole_includes2-NONSENSE] = hole_includes2_value;
  Types_terminal_map[hole_OPTMORE_BindType-NONSENSE] = hole_OPTMORE_BindType_value;
  Types_terminal_map[hole_OPTMORE_StructType-NONSENSE] = hole_OPTMORE_StructType_value;
  Types_terminal_map[hole_Types-NONSENSE] = hole_Types_value;
  Types_terminal_map[hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym-NONSENSE] = hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value;
  Types_terminal_map[hole_Enums-NONSENSE] = hole_Enums_value;
  Types_terminal_map[hole_EnumType-NONSENSE] = hole_EnumType_value;
  Types_terminal_map[hole_ALT_TypeName_SEP_commasym_NL-NONSENSE] = hole_ALT_TypeName_SEP_commasym_NL_value;
  Types_terminal_map[hole_BindType-NONSENSE] = hole_BindType_value;
  Types_terminal_map[hole_PointerType-NONSENSE] = hole_PointerType_value;
  Types_terminal_map[hole_subtypedef-NONSENSE] = hole_subtypedef_value;
  Types_terminal_map[hole_struct_type-NONSENSE] = hole_struct_type_value;
  Types_terminal_map[hole_OPTMORE_macro-NONSENSE] = hole_OPTMORE_macro_value;
  Types_terminal_map[hole_OPTMORE_CreateFunction-NONSENSE] = hole_OPTMORE_CreateFunction_value;
  Types_terminal_map[hole_StructType-NONSENSE] = hole_StructType_value;
  Types_terminal_map[hole_OPTMORE_field-NONSENSE] = hole_OPTMORE_field_value;
  Types_terminal_map[hole_OPTMORE_struct_type-NONSENSE] = hole_OPTMORE_struct_type_value;
  Types_terminal_map[hole_sub_union-NONSENSE] = hole_sub_union_value;
  Types_terminal_map[hole_OPTMORE_dotsubdotsym_Identsym-NONSENSE] = hole_OPTMORE_dotsubdotsym_Identsym_value;
  Types_terminal_map[hole_macro-NONSENSE] = hole_macro_value;
  Types_terminal_map[hole_TypeNames-NONSENSE] = hole_TypeNames_value;
  Types_terminal_map[hole_field-NONSENSE] = hole_field_value;
  Types_terminal_map[hole_TypeName-NONSENSE] = hole_TypeName_value;
  Types_terminal_map[hole_CreateFunction-NONSENSE] = hole_CreateFunction_value;
  Types_terminal_map[hole_ALT_TypeName_SEP__sym-NONSENSE] = hole_ALT_TypeName_SEP__sym_value;
}

extern int Types_lex(void);
#define SHIFT() { _Types_token = Types_lex(); if (_Types_token==0) _Types_token = Types_EOF_value; else _Types_token = Types_terminal_map[_Types_token-NONSENSE]; }
#define HOLE_ACTION(term,s) PUSH_PARSEVALUE(Pointer,Get_sub_tree(),hole); SHIFT()
#ifdef TRACE_Types_PARSE
#define REPORT(n) \
    printf ("State %d,	symbol %s,	token %s\n", n, Types_symbol_names[_Types_symbol], Types_symbol_names[_Types_token]);
#else
#define REPORT(n)
#endif
#if !defined(__GNUC__)
# define __inline__
#endif
List_Types_EnumType Parse_state_Types_OPTMORE_EnumType (void);	/* state 0 */
static int Parse_state_1 (SymbolSet followers);	/* state 1 */
static int Parse_state_2 (SymbolSet followers);	/* state 2 */
static int Parse_state_3 (SymbolSet followers);	/* state 3 */

static __inline__ int Parse_state_4 (void)	/* state 4 */
{ int n;
      n = 1; _Types_symbol = TypeName_value;
      { ParseValue me;
        Ident  full = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_TypeName");
        me->sub.PointerValue = Create_Types_TypeName(src_info, full);
      }
  return n-1;
}

static int Parse_state_5 (SymbolSet followers);	/* state 5 */
static int Parse_state_6 (SymbolSet followers);	/* state 6 */

static __inline__ int Parse_state_7 (void)	/* state 7 */
{ int n;
      n = 3; _Types_symbol = ALT_TypeName_SEP_commasym_NL_value;
      { /* alt action */
        List_Types_TypeName  tns_l = POP_PARSEVALUE (Pointer, List_Types_TypeName);
        Types_TypeName  tns = POP_PARSEVALUE (Pointer, Types_TypeName);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_TypeName(tns,tns_l),List_Types_TypeName);
      }
  return n-1;
}


static __inline__ int Parse_state_8 (void)	/* state 8 */
{ int n;
      n = 1; _Types_symbol = Enums_value;
  return n-1;
}

static int Parse_state_9 (SymbolSet followers);	/* state 9 */
static int Parse_state_10 (SymbolSet followers);	/* state 10 */
static int Parse_state_11 (SymbolSet followers);	/* state 11 */
static int Parse_state_12 (SymbolSet followers);	/* state 12 */
static int Parse_state_13 (SymbolSet followers);	/* state 13 */
static int Parse_state_14 (SymbolSet followers);	/* state 14 */
static int Parse_state_15 (SymbolSet followers);	/* state 15 */
static int Parse_state_16 (SymbolSet followers);	/* state 16 */
static int Parse_state_17 (SymbolSet followers);	/* state 17 */

static __inline__ int Parse_state_18 (void)	/* state 18 */
{ int n;
      n = 13; _Types_symbol = EnumType_value;
      { ParseValue me;
        Int  num = POP_PARSEVALUE (Int, Int);
        Ident  tag = POP_PARSEVALUE (Ident, Ident);
        Ident  str = POP_PARSEVALUE (Ident, Ident);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        List_Types_TypeName  tns = POP_PARSEVALUE (Pointer, List_Types_TypeName);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_EnumType");
        me->sub.PointerValue = Create_Types_EnumType(src_info, tns, id, str, tag, num);
      }
  return n-1;
}

static int Parse_state_19 (SymbolSet followers);	/* state 19 */

static __inline__ int Parse_state_20 (void)	/* state 20 */
{ int n;
      n = 2; _Types_symbol = OPTMORE_EnumType_value;
      { /* optmore action */
        List_Types_EnumType  enums_l = POP_PARSEVALUE (Pointer, List_Types_EnumType);
        Types_EnumType  enums = POP_PARSEVALUE (Pointer, Types_EnumType);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_EnumType(enums,enums_l),List_Types_EnumType);
      }
  return n-1;
}

List_Types_PointerType Parse_state_Types_OPTMORE_PointerType (void);	/* state 21 */
static int Parse_state_22 (SymbolSet followers);	/* state 22 */
static int Parse_state_23 (SymbolSet followers);	/* state 23 */
static int Parse_state_24 (SymbolSet followers);	/* state 24 */
static int Parse_state_25 (SymbolSet followers);	/* state 25 */
static int Parse_state_26 (SymbolSet followers);	/* state 26 */
static int Parse_state_27 (SymbolSet followers);	/* state 27 */
static int Parse_state_28 (SymbolSet followers);	/* state 28 */
static int Parse_state_29 (SymbolSet followers);	/* state 29 */
static int Parse_state_30 (SymbolSet followers);	/* state 30 */
static int Parse_state_31 (SymbolSet followers);	/* state 31 */
static int Parse_state_32 (SymbolSet followers);	/* state 32 */
static int Parse_state_33 (void);	/* state 33 */

static __inline__ int Parse_state_34 (void)	/* state 34 */
{ int n;
      n = 4; _Types_symbol = subtypedef_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        Ident  super = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_subtypedef");
        me->sub.PointerValue = Create_Types_subtypedef(src_info, super, id);
      }
  return n-1;
}

static int Parse_state_35 (SymbolSet followers);	/* state 35 */

static __inline__ int Parse_state_36 (void)	/* state 36 */
{ int n;
      n = 2; _Types_symbol = OPTMORE_subtypedef_value;
      { /* optmore action */
        List_Types_subtypedef  subs_l = POP_PARSEVALUE (Pointer, List_Types_subtypedef);
        Types_subtypedef  subs = POP_PARSEVALUE (Pointer, Types_subtypedef);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_subtypedef(subs,subs_l),List_Types_subtypedef);
      }
  return n-1;
}

static int Parse_state_37 (void);	/* state 37 */

static __inline__ int Parse_state_38 (void)	/* state 38 */
{ int n;
      n = 11; _Types_symbol = PointerType_value;
      { ParseValue me;
        List_Types_subtypedef  subs = POP_PARSEVALUE (Pointer, List_Types_subtypedef);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        Ident  id3 = POP_PARSEVALUE (Ident, Ident);
        Ident  id2 = POP_PARSEVALUE (Ident, Ident);
        Ident  id1 = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_PointerType");
        me->sub.PointerValue = Create_Types_PointerType(src_info, id1, id2, id3, id, subs);
      }
  return n-1;
}

static int Parse_state_39 (SymbolSet followers);	/* state 39 */

static __inline__ int Parse_state_40 (void)	/* state 40 */
{ int n;
      n = 2; _Types_symbol = OPTMORE_PointerType_value;
      { /* optmore action */
        List_Types_PointerType  pointers_l = POP_PARSEVALUE (Pointer, List_Types_PointerType);
        Types_PointerType  pointers = POP_PARSEVALUE (Pointer, Types_PointerType);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_PointerType(pointers,pointers_l),List_Types_PointerType);
      }
  return n-1;
}

List_Types_subtypedef Parse_state_Types_OPTMORE_subtypedef (void);	/* state 41 */
Types_includes2 Parse_state_Types_includes2 (void);	/* state 42 */
static int Parse_state_43 (SymbolSet followers);	/* state 43 */
static int Parse_state_44 (SymbolSet followers);	/* state 44 */
static int Parse_state_45 (SymbolSet followers);	/* state 45 */
static int Parse_state_46 (SymbolSet followers);	/* state 46 */
static int Parse_state_47 (void);	/* state 47 */

static __inline__ int Parse_state_48 (void)	/* state 48 */
{ int n;
      n = 3; _Types_symbol = OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_value;
      { /* opt action */
        Ident  id1 = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,id1,Ident);
      }
  return n-1;
}

static int Parse_state_49 (SymbolSet followers);	/* state 49 */
static int Parse_state_50 (SymbolSet followers);	/* state 50 */
static int Parse_state_51 (SymbolSet followers);	/* state 51 */
static int Parse_state_52 (SymbolSet followers);	/* state 52 */
static int Parse_state_53 (SymbolSet followers);	/* state 53 */
static int Parse_state_54 (SymbolSet followers);	/* state 54 */
static int Parse_state_55 (SymbolSet followers);	/* state 55 */

static __inline__ int Parse_state_56 (void)	/* state 56 */
{ int n;
      n = 4; _Types_symbol = OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value;
      { /* optmore action */
        List_Ident  uses_l = POP_PARSEVALUE (Pointer, List_Ident);
        Ident  uses = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,Create_List_Ident(uses,uses_l),List_Ident);
      }
  return n-1;
}


static __inline__ int Parse_state_57 (void)	/* state 57 */
{ int n;
      n = 8; _Types_symbol = includes2_value;
      { ParseValue me;
        List_Ident  uses = POP_PARSEVALUE (Pointer, List_Ident);
        Ident  id2 = POP_PARSEVALUE (Ident, Ident);
        Ident  id1 = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_includes2");
        me->sub.PointerValue = Create_Types_includes2(src_info, id1, id2, uses);
      }
  return n-1;
}

List_Types_BindType Parse_state_Types_OPTMORE_BindType (void);	/* state 58 */
static int Parse_state_59 (SymbolSet followers);	/* state 59 */
static int Parse_state_60 (SymbolSet followers);	/* state 60 */
static int Parse_state_61 (SymbolSet followers);	/* state 61 */
static int Parse_state_62 (SymbolSet followers);	/* state 62 */
static int Parse_state_63 (SymbolSet followers);	/* state 63 */
static int Parse_state_64 (SymbolSet followers);	/* state 64 */
static int Parse_state_65 (SymbolSet followers);	/* state 65 */
static int Parse_state_66 (SymbolSet followers);	/* state 66 */
static int Parse_state_67 (SymbolSet followers);	/* state 67 */
static int Parse_state_68 (SymbolSet followers);	/* state 68 */
static int Parse_state_69 (SymbolSet followers);	/* state 69 */
static int Parse_state_70 (SymbolSet followers);	/* state 70 */
static int Parse_state_71 (SymbolSet followers);	/* state 71 */
static int Parse_state_72 (SymbolSet followers);	/* state 72 */
static int Parse_state_73 (SymbolSet followers);	/* state 73 */
static int Parse_state_74 (SymbolSet followers);	/* state 74 */
static int Parse_state_75 (SymbolSet followers);	/* state 75 */
static int Parse_state_76 (SymbolSet followers);	/* state 76 */
static int Parse_state_77 (SymbolSet followers);	/* state 77 */
static int Parse_state_78 (SymbolSet followers);	/* state 78 */
static int Parse_state_79 (SymbolSet followers);	/* state 79 */

static __inline__ int Parse_state_80 (void)	/* state 80 */
{ int n;
      n = 22; _Types_symbol = BindType_value;
      { ParseValue me;
        Int  num = POP_PARSEVALUE (Int, Int);
        Ident  id7 = POP_PARSEVALUE (Ident, Ident);
        Ident  id6 = POP_PARSEVALUE (Ident, Ident);
        Ident  id5 = POP_PARSEVALUE (Ident, Ident);
        Ident  id4 = POP_PARSEVALUE (Ident, Ident);
        Ident  id3 = POP_PARSEVALUE (Ident, Ident);
        Ident  id2 = POP_PARSEVALUE (Ident, Ident);
        Ident  id1 = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_BindType");
        me->sub.PointerValue = Create_Types_BindType(src_info, id1, id2, id3, id4, id5, id6, id7, num);
      }
  return n-1;
}

static int Parse_state_81 (SymbolSet followers);	/* state 81 */

static __inline__ int Parse_state_82 (void)	/* state 82 */
{ int n;
      n = 2; _Types_symbol = OPTMORE_BindType_value;
      { /* optmore action */
        List_Types_BindType  binds_l = POP_PARSEVALUE (Pointer, List_Types_BindType);
        Types_BindType  binds = POP_PARSEVALUE (Pointer, Types_BindType);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_BindType(binds,binds_l),List_Types_BindType);
      }
  return n-1;
}

List_Types_StructType Parse_state_Types_OPTMORE_StructType (void);	/* state 83 */
static int Parse_state_84 (SymbolSet followers);	/* state 84 */
static int Parse_state_85 (SymbolSet followers);	/* state 85 */
static int Parse_state_86 (SymbolSet followers);	/* state 86 */
static int Parse_state_87 (SymbolSet followers);	/* state 87 */
static int Parse_state_88 (SymbolSet followers);	/* state 88 */
static int Parse_state_89 (SymbolSet followers);	/* state 89 */
static int Parse_state_90 (SymbolSet followers);	/* state 90 */
static int Parse_state_91 (SymbolSet followers);	/* state 91 */
static int Parse_state_92 (void);	/* state 92 */

static __inline__ int Parse_state_93 (void)	/* state 93 */
{ int n;
      n = 2; _Types_symbol = OPT_Identsym__USER_FIELDSsym_value;
      { /* opt action */
        Ident  user = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,user,Ident);
      }
  return n-1;
}

static int Parse_state_94 (SymbolSet followers);	/* state 94 */
static int Parse_state_95 (SymbolSet followers);	/* state 95 */
static int Parse_state_96 (SymbolSet followers);	/* state 96 */

static __inline__ int Parse_state_97 (void)	/* state 97 */
{ int n;
      n = 3; _Types_symbol = ALT_TypeName_SEP__sym_value;
      { /* alt action */
        List_Types_TypeName  ids_l = POP_PARSEVALUE (Pointer, List_Types_TypeName);
        Types_TypeName  ids = POP_PARSEVALUE (Pointer, Types_TypeName);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_TypeName(ids,ids_l),List_Types_TypeName);
      }
  return n-1;
}


static __inline__ int Parse_state_98 (void)	/* state 98 */
{ int n;
      n = 1; _Types_symbol = TypeNames_value;
  return n-1;
}

static int Parse_state_99 (SymbolSet followers);	/* state 99 */
static int Parse_state_100 (void);	/* state 100 */

static __inline__ int Parse_state_101 (void)	/* state 101 */
{ int n;
      n = 3; _Types_symbol = field_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        List_Types_TypeName  ids = POP_PARSEVALUE (Pointer, List_Types_TypeName);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_field");
        me->sub.PointerValue = Create_Types_field(src_info, ids, id);
      }
  return n-1;
}

static int Parse_state_102 (SymbolSet followers);	/* state 102 */

static __inline__ int Parse_state_103 (void)	/* state 103 */
{ int n;
      n = 2; _Types_symbol = OPTMORE_field_value;
      { /* optmore action */
        List_Types_field  fields1_l = POP_PARSEVALUE (Pointer, List_Types_field);
        Types_field  fields1 = POP_PARSEVALUE (Pointer, Types_field);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_field(fields1,fields1_l),List_Types_field);
      }
  return n-1;
}

static int Parse_state_104 (SymbolSet followers);	/* state 104 */
static int Parse_state_105 (SymbolSet followers);	/* state 105 */
static int Parse_state_106 (SymbolSet followers);	/* state 106 */

static __inline__ int Parse_state_107 (void)	/* state 107 */
{ int n;
      n = 2; _Types_symbol = OPTMORE_struct_type_value;
      { /* optmore action */
        List_Types_struct_type  sub_types_l = POP_PARSEVALUE (Pointer, List_Types_struct_type);
        Types_struct_type  sub_types = POP_PARSEVALUE (Pointer, Types_struct_type);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_struct_type(sub_types,sub_types_l),List_Types_struct_type);
      }
  return n-1;
}

static int Parse_state_108 (void);	/* state 108 */

static __inline__ int Parse_state_109 (void)	/* state 109 */
{ int n;
      n = 3; _Types_symbol = sub_union_value;
  return n-1;
}


static __inline__ int Parse_state_110 (void)	/* state 110 */
{ int n;
      n = 1; _Types_symbol = OPT_sub_union_value;
      { /* opt action */
        List_Types_struct_type  sub_types = POP_PARSEVALUE (Pointer, List_Types_struct_type);
        PUSH_PARSEVALUE(Pointer,sub_types,List_Types_struct_type);
      }
  return n-1;
}

static int Parse_state_111 (SymbolSet followers);	/* state 111 */
static int Parse_state_112 (SymbolSet followers);	/* state 112 */
static int Parse_state_113 (SymbolSet followers);	/* state 113 */

static __inline__ int Parse_state_114 (void)	/* state 114 */
{ int n;
      n = 1; _Types_symbol = OPT_Identsym_value;
      { /* opt action */
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,id,Ident);
      }
  return n-1;
}

static int Parse_state_115 (void);	/* state 115 */

static __inline__ int Parse_state_116 (void)	/* state 116 */
{ int n;
      n = 11; _Types_symbol = struct_type_value;
      { ParseValue me;
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        List_Types_field  fields2 = POP_PARSEVALUE (Pointer, List_Types_field);
        List_Types_struct_type  sub_types = POP_PARSEVALUE (Pointer, List_Types_struct_type);
        List_Types_field  fields1 = POP_PARSEVALUE (Pointer, List_Types_field);
        Ident  user = POP_PARSEVALUE (Ident, Ident);
        Ident  tag = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_struct_type");
        me->sub.PointerValue = Create_Types_struct_type(src_info, tag, user, fields1, sub_types, fields2, id);
      }
  return n-1;
}

static int Parse_state_117 (SymbolSet followers);	/* state 117 */
static int Parse_state_118 (SymbolSet followers);	/* state 118 */
static int Parse_state_119 (SymbolSet followers);	/* state 119 */
static int Parse_state_120 (SymbolSet followers);	/* state 120 */
static int Parse_state_121 (SymbolSet followers);	/* state 121 */
static int Parse_state_122 (SymbolSet followers);	/* state 122 */
static int Parse_state_123 (SymbolSet followers);	/* state 123 */
static int Parse_state_124 (SymbolSet followers);	/* state 124 */
static int Parse_state_125 (SymbolSet followers);	/* state 125 */
static int Parse_state_126 (SymbolSet followers);	/* state 126 */

static __inline__ int Parse_state_127 (void)	/* state 127 */
{ int n;
      n = 3; _Types_symbol = OPTMORE_dotsubdotsym_Identsym_value;
      { /* optmore action */
        List_Ident  types_l = POP_PARSEVALUE (Pointer, List_Ident);
        Ident  types = POP_PARSEVALUE (Ident, Ident);
        PUSH_PARSEVALUE(Pointer,Create_List_Ident(types,types_l),List_Ident);
      }
  return n-1;
}

static int Parse_state_128 (SymbolSet followers);	/* state 128 */
static int Parse_state_129 (SymbolSet followers);	/* state 129 */
static int Parse_state_130 (void);	/* state 130 */

static __inline__ int Parse_state_131 (void)	/* state 131 */
{ int n;
      n = 11; _Types_symbol = macro_value;
      { ParseValue me;
        Ident  f = POP_PARSEVALUE (Ident, Ident);
        List_Ident  types = POP_PARSEVALUE (Pointer, List_Ident);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        Ident  type = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_macro");
        me->sub.PointerValue = Create_Types_plain_macro(src_info, type, id, types, f);
      }
  return n-1;
}

static int Parse_state_132 (SymbolSet followers);	/* state 132 */
static int Parse_state_133 (SymbolSet followers);	/* state 133 */
static int Parse_state_134 (SymbolSet followers);	/* state 134 */
static int Parse_state_135 (SymbolSet followers);	/* state 135 */
static int Parse_state_136 (void);	/* state 136 */

static __inline__ int Parse_state_137 (void)	/* state 137 */
{ int n;
      n = 12; _Types_symbol = macro_value;
      { ParseValue me;
        Ident  f = POP_PARSEVALUE (Ident, Ident);
        List_Ident  types = POP_PARSEVALUE (Pointer, List_Ident);
        Ident  r = POP_PARSEVALUE (Ident, Ident);
        Ident  id = POP_PARSEVALUE (Ident, Ident);
        Ident  type = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_macro");
        me->sub.PointerValue = Create_Types_access_macro(src_info, type, id, r, types, f);
      }
  return n-1;
}

static int Parse_state_138 (SymbolSet followers);	/* state 138 */

static __inline__ int Parse_state_139 (void)	/* state 139 */
{ int n;
      n = 2; _Types_symbol = OPTMORE_macro_value;
      { /* optmore action */
        List_Types_macro  macros_l = POP_PARSEVALUE (Pointer, List_Types_macro);
        Types_macro  macros = POP_PARSEVALUE (Pointer, Types_macro);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_macro(macros,macros_l),List_Types_macro);
      }
  return n-1;
}

static int Parse_state_140 (SymbolSet followers);	/* state 140 */
static int Parse_state_141 (SymbolSet followers);	/* state 141 */

static __inline__ int Parse_state_142 (void)	/* state 142 */
{ int n;
      n = 2; _Types_symbol = CreateFunction_value;
      { ParseValue me;
        List_Types_field  fields = POP_PARSEVALUE (Pointer, List_Types_field);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_CreateFunction");
        me->sub.PointerValue = Create_Types_CreateFunction(src_info, fields);
      }
  return n-1;
}

static int Parse_state_143 (SymbolSet followers);	/* state 143 */

static __inline__ int Parse_state_144 (void)	/* state 144 */
{ int n;
      n = 2; _Types_symbol = OPTMORE_CreateFunction_value;
      { /* optmore action */
        List_Types_CreateFunction  creates_l = POP_PARSEVALUE (Pointer, List_Types_CreateFunction);
        Types_CreateFunction  creates = POP_PARSEVALUE (Pointer, Types_CreateFunction);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_CreateFunction(creates,creates_l),List_Types_CreateFunction);
      }
  return n-1;
}

static int Parse_state_145 (SymbolSet followers);	/* state 145 */
static int Parse_state_146 (SymbolSet followers);	/* state 146 */
static int Parse_state_147 (void);	/* state 147 */

static __inline__ int Parse_state_148 (void)	/* state 148 */
{ int n;
      n = 10; _Types_symbol = StructType_value;
      { ParseValue me;
        Ident  id3 = POP_PARSEVALUE (Ident, Ident);
        List_Types_CreateFunction  creates = POP_PARSEVALUE (Pointer, List_Types_CreateFunction);
        List_Types_macro  macros = POP_PARSEVALUE (Pointer, List_Types_macro);
        Types_struct_type  type = POP_PARSEVALUE (Pointer, Types_struct_type);
        Ident  id2 = POP_PARSEVALUE (Ident, Ident);
        Ident  id1 = POP_PARSEVALUE (Ident, Ident);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_StructType");
        me->sub.PointerValue = Create_Types_StructType(src_info, id1, id2, type, macros, creates, id3);
      }
  return n-1;
}

static int Parse_state_149 (SymbolSet followers);	/* state 149 */

static __inline__ int Parse_state_150 (void)	/* state 150 */
{ int n;
      n = 2; _Types_symbol = OPTMORE_StructType_value;
      { /* optmore action */
        List_Types_StructType  types_l = POP_PARSEVALUE (Pointer, List_Types_StructType);
        Types_StructType  types = POP_PARSEVALUE (Pointer, Types_StructType);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_StructType(types,types_l),List_Types_StructType);
      }
  return n-1;
}

Types_Types Parse_state_Types_Types (void);	/* state 151 */
static int Parse_state_152 (void);	/* state 152 */
static int Parse_state_153 (void);	/* state 153 */

static __inline__ int Parse_state_154 (void)	/* state 154 */
{ int n;
      n = 3; _Types_symbol = includes1_value;
  return n-1;
}

static int Parse_state_155 (SymbolSet followers);	/* state 155 */
static int Parse_state_156 (SymbolSet followers);	/* state 156 */
static int Parse_state_157 (SymbolSet followers);	/* state 157 */
static int Parse_state_158 (SymbolSet followers);	/* state 158 */
static int Parse_state_159 (SymbolSet followers);	/* state 159 */
static int Parse_state_160 (SymbolSet followers);	/* state 160 */
static int Parse_state_161 (SymbolSet followers);	/* state 161 */
static int Parse_state_162 (SymbolSet followers);	/* state 162 */
static int Parse_state_163 (SymbolSet followers);	/* state 163 */
static int Parse_state_164 (void);	/* state 164 */

static __inline__ int Parse_state_165 (void)	/* state 165 */
{ int n;
      n = 4; _Types_symbol = RootDecl_value;
  return n-1;
}

static int Parse_state_166 (SymbolSet followers);	/* state 166 */

static __inline__ int Parse_state_167 (void)	/* state 167 */
{ int n;
      n = 9; _Types_symbol = Types_value;
      { ParseValue me;
        List_Types_StructType  types = POP_PARSEVALUE (Pointer, List_Types_StructType);
        Ident  r2 = POP_PARSEVALUE (Ident, Ident);
        Ident  r1 = POP_PARSEVALUE (Ident, Ident);
        List_Types_BindType  binds = POP_PARSEVALUE (Pointer, List_Types_BindType);
        List_Types_subtypedef  impdefs = POP_PARSEVALUE (Pointer, List_Types_subtypedef);
        Types_includes2  inc2 = POP_PARSEVALUE (Pointer, Types_includes2);
        List_Types_subtypedef  subs = POP_PARSEVALUE (Pointer, List_Types_subtypedef);
        List_Types_PointerType  pointers = POP_PARSEVALUE (Pointer, List_Types_PointerType);
        List_Types_EnumType  enums = POP_PARSEVALUE (Pointer, List_Types_EnumType);
        SrcInfo src_info = make_post_src_info(GetFirstLine(), SCAN_END_POSITION);
        me = PushParseValue("Types_Types");
        me->sub.PointerValue = Create_Types_Types(src_info, enums, pointers, subs, inc2, impdefs, binds, r1, r2, types);
        Decorate_Types(me->sub.PointerValue);
      }
  return n-1;
}

List_Ident Parse_state_Types_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym (void);	/* state 168 */
List_Types_TypeName Parse_state_Types_Enums (void);	/* state 169 */
Types_EnumType Parse_state_Types_EnumType (void);	/* state 170 */
List_Types_TypeName Parse_state_Types_ALT_TypeName_SEP_commasym_NL (void);	/* state 171 */
Types_BindType Parse_state_Types_BindType (void);	/* state 172 */
Types_PointerType Parse_state_Types_PointerType (void);	/* state 173 */
Types_subtypedef Parse_state_Types_subtypedef (void);	/* state 174 */
Types_struct_type Parse_state_Types_struct_type (void);	/* state 175 */
List_Types_macro Parse_state_Types_OPTMORE_macro (void);	/* state 176 */
List_Types_CreateFunction Parse_state_Types_OPTMORE_CreateFunction (void);	/* state 177 */
Types_StructType Parse_state_Types_StructType (void);	/* state 178 */
List_Types_field Parse_state_Types_OPTMORE_field (void);	/* state 179 */
List_Types_struct_type Parse_state_Types_OPTMORE_struct_type (void);	/* state 180 */
List_Types_struct_type Parse_state_Types_sub_union (void);	/* state 181 */
List_Ident Parse_state_Types_OPTMORE_dotsubdotsym_Identsym (void);	/* state 182 */
Types_macro Parse_state_Types_macro (void);	/* state 183 */
List_Types_TypeName Parse_state_Types_TypeNames (void);	/* state 184 */
Types_field Parse_state_Types_field (void);	/* state 185 */
Types_TypeName Parse_state_Types_TypeName (void);	/* state 186 */
Types_CreateFunction Parse_state_Types_CreateFunction (void);	/* state 187 */
List_Types_TypeName Parse_state_Types_ALT_TypeName_SEP__sym (void);	/* state 188 */

/* directors of state 0
   hole_EnumType typedefsym 
 */
List_Types_EnumType Parse_state_Types_OPTMORE_EnumType (void)	/* state 0 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x400, 0x0, 0x20 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(0);
    switch (_Types_symbol) {
    case OPTMORE_EnumType_value:
      n = 1; break; /* accept OPTMORE_EnumType  ->  . EnumType OPTMORE_EnumType       followers: Types_EOF  */
    case typedefsym_value:
      {
        static Int my_followers[] = { 0x400, 0x10000000, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_EnumType_value: HOLE_ACTION (0, "EnumType");
    case EnumType_value:
      {
        n = Parse_state_19(followers);
        break;
      }
    default:
    /* default item:OPTMORE_EnumType  ->  .    followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_EnumType_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Types_EnumType);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_EnumType")->sub.PointerValue;
}

/* directors of state 1
   enumsym 
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
   openchainsym 
 */
static int Parse_state_2 (SymbolSet followers)	/* state 2 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_3(followers);
      }
  return n-1;
}

/* directors of state 3
   hole_Enums hole_ALT_TypeName_SEP_commasym_NL hole_TypeName Identsym 
 */
static int Parse_state_3 (SymbolSet followers)	/* state 3 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0x200050 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(3);
    switch (_Types_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x2000, 0x2000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        static Int my_followers[] = { 0x2000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_5(_followers);
        break;
      }
    case hole_ALT_TypeName_SEP_commasym_NL_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP_commasym_NL_value:
      {
        static Int my_followers[] = { 0x2000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_8();
        break;
      }
    case hole_Enums_value: HOLE_ACTION (0, "List_TypeName");
    case Enums_value:
      {
        n = Parse_state_9(followers);
        break;
      }
    default:
    /* default item:EnumType  ->  typedefsym enumsym openchainsym . Enums closechainsym Identsym semicolonsym externspacecharspacestarsym Identsym underscorenamesopenbrkclosebrksemicolonsym hashdefinespaceNUMunderscoresym Identsym Intsym       followers: Types_EOF hole_OPTMORE_EnumType hole_EnumType typedefsym hole_OPTMORE_PointerType hole_PointerType hashifndefspaceDEFunderscoreTYPEunderscoresym hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_includes2 hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym  */
/* nt = 0x822ecf8 */
      InputError (SCAN_POSITION, TRUE, "Enums expected");
      PUSH_PARSEVALUE(Pointer,0,List_Types_TypeName);
      _Types_symbol = Enums_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 5
   commasym 
 */
static int Parse_state_5 (SymbolSet followers)	/* state 5 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x2000000, 0x0 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(5);
    switch (_Types_symbol) {
    case commasym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_6(followers);
        break;
      }
    default:
    /* default item:ALT_TypeName_SEP_commasym_NL  ->  TypeName .    followers: closechainsym Types_EOF  */
      n = 1; _Types_symbol = ALT_TypeName_SEP_commasym_NL_value;
      { /* alt action */
        Types_TypeName  tns = POP_PARSEVALUE (Pointer, Types_TypeName);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_TypeName(tns,NULL),List_Types_TypeName);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 6
   hole_ALT_TypeName_SEP_commasym_NL hole_TypeName Identsym 
 */
static int Parse_state_6 (SymbolSet followers)	/* state 6 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0x200040 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(6);
    switch (_Types_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        n = Parse_state_5(followers);
        break;
      }
    case hole_ALT_TypeName_SEP_commasym_NL_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP_commasym_NL_value:
      {
        n = Parse_state_7();
        break;
      }
    default:
    /* default item:ALT_TypeName_SEP_commasym_NL  ->  TypeName commasym . ALT_TypeName_SEP_commasym_NL      followers: closechainsym Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_TypeName_SEP_commasym_NL expected");
      PUSH_PARSEVALUE(Pointer,0,List_Types_TypeName);
      _Types_symbol = ALT_TypeName_SEP_commasym_NL_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 9
   closechainsym 
 */
static int Parse_state_9 (SymbolSet followers)	/* state 9 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_10(followers);
      }
  return n-1;
}

/* directors of state 10
   Identsym 
 */
static int Parse_state_10 (SymbolSet followers)	/* state 10 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_11(followers);
      }
  return n-1;
}

/* directors of state 11
   semicolonsym 
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
   externspacecharspacestarsym 
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
   Identsym 
 */
static int Parse_state_13 (SymbolSet followers)	/* state 13 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_14(followers);
      }
  return n-1;
}

/* directors of state 14
   underscorenamesopenbrkclosebrksemicolonsym 
 */
static int Parse_state_14 (SymbolSet followers)	/* state 14 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_15(followers);
      }
  return n-1;
}

/* directors of state 15
   hashdefinespaceNUMunderscoresym 
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
   Identsym 
 */
static int Parse_state_16 (SymbolSet followers)	/* state 16 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_17(followers);
      }
  return n-1;
}

/* directors of state 17
   Intsym 
 */
static int Parse_state_17 (SymbolSet followers)	/* state 17 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Types_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_18();
      }
  return n-1;
}

/* directors of state 19
   hole_OPTMORE_EnumType hole_EnumType typedefsym 
 */
static int Parse_state_19 (SymbolSet followers)	/* state 19 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x400, 0x10000000, 0x20 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(19);
    switch (_Types_symbol) {
    case typedefsym_value:
      {
        static Int my_followers[] = { 0x400, 0x10000000, 0x20 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_EnumType_value: HOLE_ACTION (0, "EnumType");
    case EnumType_value:
      {
        n = Parse_state_19(followers);
        break;
      }
    case hole_OPTMORE_EnumType_value: HOLE_ACTION (0, "List_EnumType");
    case OPTMORE_EnumType_value:
      {
        n = Parse_state_20();
        break;
      }
    default:
    /* default item:OPTMORE_EnumType  ->  EnumType . OPTMORE_EnumType       followers: Types_EOF hole_OPTMORE_PointerType hole_PointerType hashifndefspaceDEFunderscoreTYPEunderscoresym hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_includes2 hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_EnumType);
      _Types_symbol = OPTMORE_EnumType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 21
   hole_PointerType hashifndefspaceDEFunderscoreTYPEunderscoresym 
 */
List_Types_PointerType Parse_state_Types_OPTMORE_PointerType (void)	/* state 21 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x40000000, 0x0, 0x100 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(21);
    switch (_Types_symbol) {
    case OPTMORE_PointerType_value:
      n = 1; break; /* accept OPTMORE_PointerType  ->  . PointerType OPTMORE_PointerType      followers: Types_EOF  */
    case hashifndefspaceDEFunderscoreTYPEunderscoresym_value:
      {
        static Int my_followers[] = { 0x40000000, 0x20000000, 0x100 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_22(_followers);
        break;
      }
    case hole_PointerType_value: HOLE_ACTION (0, "PointerType");
    case PointerType_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    default:
    /* default item:OPTMORE_PointerType  ->  . followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_PointerType_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Types_PointerType);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_PointerType")->sub.PointerValue;
}

/* directors of state 22
   Identsym 
 */
static int Parse_state_22 (SymbolSet followers)	/* state 22 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_23(followers);
      }
  return n-1;
}

/* directors of state 23
   hashdefinespaceDEFunderscoreTYPEunderscoresym 
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
   Identsym 
 */
static int Parse_state_24 (SymbolSet followers)	/* state 24 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_25(followers);
      }
  return n-1;
}

/* directors of state 25
   typedefspacestructspacesunderscoresym 
 */
static int Parse_state_25 (SymbolSet followers)	/* state 25 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_26(followers);
      }
  return n-1;
}

/* directors of state 26
   Identsym 
 */
static int Parse_state_26 (SymbolSet followers)	/* state 26 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_27(followers);
      }
  return n-1;
}

/* directors of state 27
   starsym 
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
   Identsym 
 */
static int Parse_state_28 (SymbolSet followers)	/* state 28 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_29(followers);
      }
  return n-1;
}

/* directors of state 29
   semicolonsym 
 */
static int Parse_state_29 (SymbolSet followers)	/* state 29 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_30(followers);
      }
  return n-1;
}

/* directors of state 30
   hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hashendifsym 
 */
static int Parse_state_30 (SymbolSet followers)	/* state 30 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x4000000c, 0x200 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(30);
    switch (_Types_symbol) {
    case typedefspacesym_value:
      {
        static Int my_followers[] = { 0x0, 0x4000000c, 0x200 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(_followers);
        break;
      }
    case hole_subtypedef_value: HOLE_ACTION (0, "subtypedef");
    case subtypedef_value:
      {
        static Int my_followers[] = { 0x0, 0x4, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_35(_followers);
        break;
      }
    case hole_OPTMORE_subtypedef_value: HOLE_ACTION (0, "List_subtypedef");
    case OPTMORE_subtypedef_value:
      {
        n = Parse_state_37();
        break;
      }
    default:
    /* default item:PointerType  ->  hashifndefspaceDEFunderscoreTYPEunderscoresym Identsym hashdefinespaceDEFunderscoreTYPEunderscoresym Identsym typedefspacestructspacesunderscoresym Identsym starsym Identsym semicolonsym . OPTMORE_subtypedef hashendifsym   followers: Types_EOF hole_OPTMORE_PointerType hole_PointerType hashifndefspaceDEFunderscoreTYPEunderscoresym hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_includes2 hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_subtypedef);
      _Types_symbol = OPTMORE_subtypedef_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 31
   Identsym 
 */
static int Parse_state_31 (SymbolSet followers)	/* state 31 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_32(followers);
      }
  return n-1;
}

/* directors of state 32
   Identsym 
 */
static int Parse_state_32 (SymbolSet followers)	/* state 32 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_33();
      }
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
   hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym 
 */
static int Parse_state_35 (SymbolSet followers)	/* state 35 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x40000008, 0x200 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(35);
    switch (_Types_symbol) {
    case typedefspacesym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000008, 0x200 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(_followers);
        break;
      }
    case hole_subtypedef_value: HOLE_ACTION (0, "subtypedef");
    case subtypedef_value:
      {
        n = Parse_state_35(followers);
        break;
      }
    case hole_OPTMORE_subtypedef_value: HOLE_ACTION (0, "List_subtypedef");
    case OPTMORE_subtypedef_value:
      {
        n = Parse_state_36();
        break;
      }
    default:
    /* default item:OPTMORE_subtypedef  ->  subtypedef . OPTMORE_subtypedef followers: hashendifsym Types_EOF hole_includes2 hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym hole_OPTMORE_BindType hole_BindType typedefspaceBindspaceBindunderscoresym externsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_subtypedef);
      _Types_symbol = OPTMORE_subtypedef_value; n = 0;
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
   hole_OPTMORE_PointerType hole_PointerType hashifndefspaceDEFunderscoreTYPEunderscoresym 
 */
static int Parse_state_39 (SymbolSet followers)	/* state 39 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x40000000, 0x20000000, 0x100 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(39);
    switch (_Types_symbol) {
    case hashifndefspaceDEFunderscoreTYPEunderscoresym_value:
      {
        static Int my_followers[] = { 0x40000000, 0x20000000, 0x100 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_22(_followers);
        break;
      }
    case hole_PointerType_value: HOLE_ACTION (0, "PointerType");
    case PointerType_value:
      {
        n = Parse_state_39(followers);
        break;
      }
    case hole_OPTMORE_PointerType_value: HOLE_ACTION (0, "List_PointerType");
    case OPTMORE_PointerType_value:
      {
        n = Parse_state_40();
        break;
      }
    default:
    /* default item:OPTMORE_PointerType  ->  PointerType . OPTMORE_PointerType      followers: Types_EOF hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_includes2 hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_PointerType);
      _Types_symbol = OPTMORE_PointerType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 41
   hole_subtypedef typedefspacesym 
 */
List_Types_subtypedef Parse_state_Types_OPTMORE_subtypedef (void)	/* state 41 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x8, 0x200 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(41);
    switch (_Types_symbol) {
    case OPTMORE_subtypedef_value:
      n = 1; break; /* accept OPTMORE_subtypedef  ->  . subtypedef OPTMORE_subtypedef followers: Types_EOF  */
    case typedefspacesym_value:
      {
        static Int my_followers[] = { 0x0, 0x40000008, 0x200 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(_followers);
        break;
      }
    case hole_subtypedef_value: HOLE_ACTION (0, "subtypedef");
    case subtypedef_value:
      {
        n = Parse_state_35(followers);
        break;
      }
    default:
    /* default item:OPTMORE_subtypedef  ->  .  followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_subtypedef_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Types_subtypedef);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_subtypedef")->sub.PointerValue;
}

/* directors of state 42
   hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym 
 */
Types_includes2 Parse_state_Types_includes2 (void)	/* state 42 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x10, 0x0, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(42);
    switch (_Types_symbol) {
    case includes2_value:
      n = 1; break; /* accept includes2  ->  . hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym hashincludespacelessthanfrontslashSymTabdothgreaterthansym OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym hashincludespacebackslashdoublequotesym Identsym underscoredefsdothbackslashdoublequotesym OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym        followers: Types_EOF  */
    case hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_43(followers);
        break;
      }
    default:
    /* default item:includes2  ->  . hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym hashincludespacelessthanfrontslashSymTabdothgreaterthansym OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym hashincludespacebackslashdoublequotesym Identsym underscoredefsdothbackslashdoublequotesym OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym   followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym expected");
      dont_shift = TRUE; _Types_symbol = hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_includes2")->sub.PointerValue;
}

/* directors of state 43
   hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym 
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
   hashincludespacelessthanfrontslashSymTabdothgreaterthansym 
 */
static int Parse_state_44 (SymbolSet followers)	/* state 44 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_45(followers);
      }
  return n-1;
}

/* directors of state 45
   hashincludespacebackslashdoublequotesym 
 */
static int Parse_state_45 (SymbolSet followers)	/* state 45 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x80, 0x0, 0x0 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(45);
    switch (_Types_symbol) {
    case hashincludespacebackslashdoublequotesym_value:
      {
        static Int my_followers[] = { 0x80, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_46(_followers);
        break;
      }
    case OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_value:
      {
        n = Parse_state_49(followers);
        break;
      }
    default:
    /* default item:includes2  ->  hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym hashincludespacelessthanfrontslashSymTabdothgreaterthansym . OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym hashincludespacebackslashdoublequotesym Identsym underscoredefsdothbackslashdoublequotesym OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym        followers: Types_EOF hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_OPTMORE_BindType hole_BindType typedefspaceBindspaceBindunderscoresym externsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      _Types_symbol = OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 46
   Identsym 
 */
static int Parse_state_46 (SymbolSet followers)	/* state 46 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_47();
      }
  return n-1;
}

static int Parse_state_47 (void)	/* state 47 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_48();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 49
   hashincludespacebackslashdoublequotesym 
 */
static int Parse_state_49 (SymbolSet followers)	/* state 49 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_50(followers);
      }
  return n-1;
}

/* directors of state 50
   Identsym 
 */
static int Parse_state_50 (SymbolSet followers)	/* state 50 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_51(followers);
      }
  return n-1;
}

/* directors of state 51
   underscoredefsdothbackslashdoublequotesym 
 */
static int Parse_state_51 (SymbolSet followers)	/* state 51 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_52(followers);
      }
  return n-1;
}

/* directors of state 52
   hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym hashincludespacebackslashdoublequotesym 
 */
static int Parse_state_52 (SymbolSet followers)	/* state 52 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x80, 0x0, 0x8 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(52);
    switch (_Types_symbol) {
    case hashincludespacebackslashdoublequotesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_53(followers);
        break;
      }
    case hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value:
      {
        n = Parse_state_57();
        break;
      }
    default:
    /* default item:includes2  ->  hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym hashincludespacelessthanfrontslashprintunderscoresupportdothgreaterthansym hashincludespacelessthanfrontslashSymTabdothgreaterthansym OPT_hashincludespacebackslashdoublequotesym_Identsym_underscoreparsedothbackslashdoublequotesym hashincludespacebackslashdoublequotesym Identsym underscoredefsdothbackslashdoublequotesym . OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym        followers: Types_EOF hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_OPTMORE_BindType hole_BindType typedefspaceBindspaceBindunderscoresym externsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _Types_symbol = OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 53
   Identsym 
 */
static int Parse_state_53 (SymbolSet followers)	/* state 53 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_54(followers);
      }
  return n-1;
}

/* directors of state 54
   dothbackslashdoublequotesym 
 */
static int Parse_state_54 (SymbolSet followers)	/* state 54 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_55(followers);
      }
  return n-1;
}

/* directors of state 55
   hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym hashincludespacebackslashdoublequotesym 
 */
static int Parse_state_55 (SymbolSet followers)	/* state 55 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x80, 0x0, 0x8 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(55);
    switch (_Types_symbol) {
    case hashincludespacebackslashdoublequotesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_53(followers);
        break;
      }
    case hole_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value:
      {
        n = Parse_state_56();
        break;
      }
    default:
    /* default item:OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym  ->  hashincludespacebackslashdoublequotesym Identsym dothbackslashdoublequotesym . OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym   followers: Types_EOF hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_OPTMORE_BindType hole_BindType typedefspaceBindspaceBindunderscoresym externsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _Types_symbol = OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 58
   hole_BindType typedefspaceBindspaceBindunderscoresym 
 */
List_Types_BindType Parse_state_Types_OPTMORE_BindType (void)	/* state 58 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x80000, 0x0, 0x80 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(58);
    switch (_Types_symbol) {
    case OPTMORE_BindType_value:
      n = 1; break; /* accept OPTMORE_BindType  ->  . BindType OPTMORE_BindType       followers: Types_EOF  */
    case typedefspaceBindspaceBindunderscoresym_value:
      {
        static Int my_followers[] = { 0x80000, 0x0, 0x81 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_59(_followers);
        break;
      }
    case hole_BindType_value: HOLE_ACTION (0, "BindType");
    case BindType_value:
      {
        n = Parse_state_81(followers);
        break;
      }
    default:
    /* default item:OPTMORE_BindType  ->  .    followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_BindType_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Types_BindType);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_BindType")->sub.PointerValue;
}

/* directors of state 59
   Identsym 
 */
static int Parse_state_59 (SymbolSet followers)	/* state 59 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_60(followers);
      }
  return n-1;
}

/* directors of state 60
   semicolonsym 
 */
static int Parse_state_60 (SymbolSet followers)	/* state 60 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_61(followers);
      }
  return n-1;
}

/* directors of state 61
   typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym 
 */
static int Parse_state_61 (SymbolSet followers)	/* state 61 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_62(followers);
      }
  return n-1;
}

/* directors of state 62
   Identsym 
 */
static int Parse_state_62 (SymbolSet followers)	/* state 62 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_63(followers);
      }
  return n-1;
}

/* directors of state 63
   semicolonsym 
 */
static int Parse_state_63 (SymbolSet followers)	/* state 63 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_64(followers);
      }
  return n-1;
}

/* directors of state 64
   hashdefinespaceListunderscoreBindunderscoresym 
 */
static int Parse_state_64 (SymbolSet followers)	/* state 64 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_65(followers);
      }
  return n-1;
}

/* directors of state 65
   Identsym 
 */
static int Parse_state_65 (SymbolSet followers)	/* state 65 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_66(followers);
      }
  return n-1;
}

/* directors of state 66
   underscoredataopenparxcloseparsym 
 */
static int Parse_state_66 (SymbolSet followers)	/* state 66 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_67(followers);
      }
  return n-1;
}

/* directors of state 67
   openparBindunderscoresym 
 */
static int Parse_state_67 (SymbolSet followers)	/* state 67 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_68(followers);
      }
  return n-1;
}

/* directors of state 68
   Identsym 
 */
static int Parse_state_68 (SymbolSet followers)	/* state 68 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_69(followers);
      }
  return n-1;
}

/* directors of state 69
   closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym 
 */
static int Parse_state_69 (SymbolSet followers)	/* state 69 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_70(followers);
      }
  return n-1;
}

/* directors of state 70
   hashdefinespaceListunderscoreBindunderscoresym 
 */
static int Parse_state_70 (SymbolSet followers)	/* state 70 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_71(followers);
      }
  return n-1;
}

/* directors of state 71
   Identsym 
 */
static int Parse_state_71 (SymbolSet followers)	/* state 71 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_72(followers);
      }
  return n-1;
}

/* directors of state 72
   underscorenextopenparxcloseparsym 
 */
static int Parse_state_72 (SymbolSet followers)	/* state 72 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_73(followers);
      }
  return n-1;
}

/* directors of state 73
   openparListunderscoreBindunderscoresym 
 */
static int Parse_state_73 (SymbolSet followers)	/* state 73 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_74(followers);
      }
  return n-1;
}

/* directors of state 74
   Identsym 
 */
static int Parse_state_74 (SymbolSet followers)	/* state 74 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_75(followers);
      }
  return n-1;
}

/* directors of state 75
   closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym 
 */
static int Parse_state_75 (SymbolSet followers)	/* state 75 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_76(followers);
      }
  return n-1;
}

/* directors of state 76
   hashdefinespaceBindunderscoresym 
 */
static int Parse_state_76 (SymbolSet followers)	/* state 76 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_77(followers);
      }
  return n-1;
}

/* directors of state 77
   Identsym 
 */
static int Parse_state_77 (SymbolSet followers)	/* state 77 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_78(followers);
      }
  return n-1;
}

/* directors of state 78
   _kindsym 
 */
static int Parse_state_78 (SymbolSet followers)	/* state 78 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_79(followers);
      }
  return n-1;
}

/* directors of state 79
   Intsym 
 */
static int Parse_state_79 (SymbolSet followers)	/* state 79 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Int,Types_lval.Intsym_type,Int);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_80();
      }
  return n-1;
}

/* directors of state 81
   hole_OPTMORE_BindType hole_BindType typedefspaceBindspaceBindunderscoresym 
 */
static int Parse_state_81 (SymbolSet followers)	/* state 81 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x80000, 0x0, 0x81 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(81);
    switch (_Types_symbol) {
    case typedefspaceBindspaceBindunderscoresym_value:
      {
        static Int my_followers[] = { 0x80000, 0x0, 0x81 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_59(_followers);
        break;
      }
    case hole_BindType_value: HOLE_ACTION (0, "BindType");
    case BindType_value:
      {
        n = Parse_state_81(followers);
        break;
      }
    case hole_OPTMORE_BindType_value: HOLE_ACTION (0, "List_BindType");
    case OPTMORE_BindType_value:
      {
        n = Parse_state_82();
        break;
      }
    default:
    /* default item:OPTMORE_BindType  ->  BindType . OPTMORE_BindType       followers: Types_EOF externsym  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_BindType);
      _Types_symbol = OPTMORE_BindType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 83
   hole_StructType hashifndefspaceDEFunderscoreSTRUCTunderscoresym 
 */
List_Types_StructType Parse_state_Types_OPTMORE_StructType (void)	/* state 83 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x40, 0x2000 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(83);
    switch (_Types_symbol) {
    case OPTMORE_StructType_value:
      n = 1; break; /* accept OPTMORE_StructType  ->  . StructType OPTMORE_StructType followers: Types_EOF  */
    case hashifndefspaceDEFunderscoreSTRUCTunderscoresym_value:
      {
        static Int my_followers[] = { 0x0, 0x40, 0x2002 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84(_followers);
        break;
      }
    case hole_StructType_value: HOLE_ACTION (0, "StructType");
    case StructType_value:
      {
        n = Parse_state_149(followers);
        break;
      }
    default:
    /* default item:OPTMORE_StructType  ->  .  followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_StructType_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Types_StructType);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_StructType")->sub.PointerValue;
}

/* directors of state 84
   Identsym 
 */
static int Parse_state_84 (SymbolSet followers)	/* state 84 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_85(followers);
      }
  return n-1;
}

/* directors of state 85
   hashdefinespaceDEFunderscoreSTRUCTunderscoresym 
 */
static int Parse_state_85 (SymbolSet followers)	/* state 85 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_86(followers);
      }
  return n-1;
}

/* directors of state 86
   Identsym 
 */
static int Parse_state_86 (SymbolSet followers)	/* state 86 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_87(followers);
      }
  return n-1;
}

/* directors of state 87
   hole_struct_type structsym 
 */
static int Parse_state_87 (SymbolSet followers)	/* state 87 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x400, 0x400 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(87);
    switch (_Types_symbol) {
    case structsym_value:
      {
        static Int my_followers[] = { 0x0, 0x404100, 0x441800 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88(_followers);
        break;
      }
    case hole_struct_type_value: HOLE_ACTION (0, "struct_type");
    case struct_type_value:
      {
        n = Parse_state_117(followers);
        break;
      }
    default:
    /* default item:StructType  ->  hashifndefspaceDEFunderscoreSTRUCTunderscoresym Identsym hashdefinespaceDEFunderscoreSTRUCTunderscoresym Identsym . struct_type OPTMORE_macro OPTMORE_CreateFunction hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym Identsym spacestarslashsym    followers: hole_OPTMORE_StructType hole_StructType hashifndefspaceDEFunderscoreSTRUCTunderscoresym Types_EOF  */
/* nt = 0x8238e60 */
      InputError (SCAN_POSITION, TRUE, "struct_type expected");
      PUSH_PARSEVALUE(Pointer,0,Types_struct_type);
      _Types_symbol = struct_type_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 88
   s_sym 
 */
static int Parse_state_88 (SymbolSet followers)	/* state 88 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_89(followers);
      }
  return n-1;
}

/* directors of state 89
   Identsym 
 */
static int Parse_state_89 (SymbolSet followers)	/* state 89 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_90(followers);
      }
  return n-1;
}

/* directors of state 90
   openchainsym 
 */
static int Parse_state_90 (SymbolSet followers)	/* state 90 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_91(followers);
      }
  return n-1;
}

/* directors of state 91
   hole_sub_union unionspaceopenchainsym hole_OPTMORE_field hole_field hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym closechainsym 
 */
static int Parse_state_91 (SymbolSet followers)	/* state 91 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x2100, 0x1000, 0xb94000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(91);
    switch (_Types_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x2100, 0x1000, 0xb94000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_92();
        break;
      }
    case OPT_Identsym__USER_FIELDSsym_value:
      {
        n = Parse_state_94(followers);
        break;
      }
    default:
    /* default item:struct_type  ->  structsym s_sym Identsym openchainsym . OPT_Identsym__USER_FIELDSsym OPTMORE_field OPT_sub_union OPTMORE_field closechainsym OPT_Identsym semicolonsym followers: hole_OPTMORE_macro hole_macro hashdefinesym hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_struct_type hole_struct_type structsym closechainspacesubsemicolonsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      _Types_symbol = OPT_Identsym__USER_FIELDSsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_92 (void)	/* state 92 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_93();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 94
   hole_sub_union unionspaceopenchainsym hole_OPTMORE_field hole_field hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym closechainsym 
 */
static int Parse_state_94 (SymbolSet followers)	/* state 94 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x2100, 0x1000, 0xb94000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(94);
    switch (_Types_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x2100, 0x9000, 0xb94000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        static Int my_followers[] = { 0x2100, 0x1000, 0xb94000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_95(_followers);
        break;
      }
    case hole_ALT_TypeName_SEP__sym_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP__sym_value:
      {
        static Int my_followers[] = { 0x2100, 0x1000, 0xb94000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_98();
        break;
      }
    case hole_TypeNames_value: HOLE_ACTION (0, "List_TypeName");
    case TypeNames_value:
      {
        static Int my_followers[] = { 0x2100, 0x1000, 0xb94000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_99(_followers);
        break;
      }
    case hole_field_value: HOLE_ACTION (0, "field");
    case field_value:
      {
        static Int my_followers[] = { 0x2100, 0x1000, 0xb94000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_102(_followers);
        break;
      }
    case hole_OPTMORE_field_value: HOLE_ACTION (0, "List_field");
    case OPTMORE_field_value:
      {
        n = Parse_state_104(followers);
        break;
      }
    default:
    /* default item:struct_type  ->  structsym s_sym Identsym openchainsym OPT_Identsym__USER_FIELDSsym . OPTMORE_field OPT_sub_union OPTMORE_field closechainsym OPT_Identsym semicolonsym followers: hole_OPTMORE_macro hole_macro hashdefinesym hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_struct_type hole_struct_type structsym closechainspacesubsemicolonsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_field);
      _Types_symbol = OPTMORE_field_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 95
   _sym 
 */
static int Parse_state_95 (SymbolSet followers)	/* state 95 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x8000, 0x0 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(95);
    switch (_Types_symbol) {
    case _sym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_96(followers);
        break;
      }
    default:
    /* default item:ALT_TypeName_SEP__sym  ->  TypeName .   followers: Identsym Types_EOF  */
      n = 1; _Types_symbol = ALT_TypeName_SEP__sym_value;
      { /* alt action */
        Types_TypeName  ids = POP_PARSEVALUE (Pointer, Types_TypeName);
        PUSH_PARSEVALUE(Pointer,Create_List_Types_TypeName(ids,NULL),List_Types_TypeName);
      }
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 96
   hole_ALT_TypeName_SEP__sym hole_TypeName Identsym 
 */
static int Parse_state_96 (SymbolSet followers)	/* state 96 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0xa00000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(96);
    switch (_Types_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        n = Parse_state_95(followers);
        break;
      }
    case hole_ALT_TypeName_SEP__sym_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP__sym_value:
      {
        n = Parse_state_97();
        break;
      }
    default:
    /* default item:ALT_TypeName_SEP__sym  ->  TypeName _sym . ALT_TypeName_SEP__sym        followers: Identsym Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_TypeName_SEP__sym expected");
      PUSH_PARSEVALUE(Pointer,0,List_Types_TypeName);
      _Types_symbol = ALT_TypeName_SEP__sym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 99
   Identsym 
 */
static int Parse_state_99 (SymbolSet followers)	/* state 99 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_100();
      }
  return n-1;
}

static int Parse_state_100 (void)	/* state 100 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_101();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 102
   hole_OPTMORE_field hole_field hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym 
 */
static int Parse_state_102 (SymbolSet followers)	/* state 102 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0xb84000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(102);
    switch (_Types_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100, 0x8000, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_95(_followers);
        break;
      }
    case hole_ALT_TypeName_SEP__sym_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP__sym_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_98();
        break;
      }
    case hole_TypeNames_value: HOLE_ACTION (0, "List_TypeName");
    case TypeNames_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_99(_followers);
        break;
      }
    case hole_field_value: HOLE_ACTION (0, "field");
    case field_value:
      {
        n = Parse_state_102(followers);
        break;
      }
    case hole_OPTMORE_field_value: HOLE_ACTION (0, "List_field");
    case OPTMORE_field_value:
      {
        n = Parse_state_103();
        break;
      }
    default:
    /* default item:OPTMORE_field  ->  field . OPTMORE_field        followers: hole_sub_union unionspaceopenchainsym hole_OPTMORE_field hole_field hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym closechainsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_field);
      _Types_symbol = OPTMORE_field_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 104
   hole_sub_union unionspaceopenchainsym hole_OPTMORE_field hole_field hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym closechainsym 
 */
static int Parse_state_104 (SymbolSet followers)	/* state 104 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x2100, 0x1000, 0xb94000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(104);
    switch (_Types_symbol) {
    case unionspaceopenchainsym_value:
      {
        static Int my_followers[] = { 0x2100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_105(_followers);
        break;
      }
    case hole_sub_union_value: HOLE_ACTION (0, "List_struct_type");
    case sub_union_value:
      {
        static Int my_followers[] = { 0x2100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_110();
        break;
      }
    case OPT_sub_union_value:
      {
        n = Parse_state_111(followers);
        break;
      }
    default:
    /* default item:struct_type  ->  structsym s_sym Identsym openchainsym OPT_Identsym__USER_FIELDSsym OPTMORE_field . OPT_sub_union OPTMORE_field closechainsym OPT_Identsym semicolonsym followers: hole_OPTMORE_macro hole_macro hashdefinesym hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_struct_type hole_struct_type structsym closechainspacesubsemicolonsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_struct_type);
      _Types_symbol = OPT_sub_union_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 105
   hole_OPTMORE_struct_type hole_struct_type structsym closechainspacesubsemicolonsym 
 */
static int Parse_state_105 (SymbolSet followers)	/* state 105 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x2400, 0x8400 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(105);
    switch (_Types_symbol) {
    case structsym_value:
      {
        static Int my_followers[] = { 0x0, 0x2400, 0x8400 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88(_followers);
        break;
      }
    case hole_struct_type_value: HOLE_ACTION (0, "struct_type");
    case struct_type_value:
      {
        static Int my_followers[] = { 0x0, 0x2000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_106(_followers);
        break;
      }
    case hole_OPTMORE_struct_type_value: HOLE_ACTION (0, "List_struct_type");
    case OPTMORE_struct_type_value:
      {
        n = Parse_state_108();
        break;
      }
    default:
    /* default item:sub_union  ->  unionspaceopenchainsym . OPTMORE_struct_type closechainspacesubsemicolonsym      followers: hole_OPTMORE_field hole_field hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym closechainsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_struct_type);
      _Types_symbol = OPTMORE_struct_type_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 106
   hole_OPTMORE_struct_type hole_struct_type structsym 
 */
static int Parse_state_106 (SymbolSet followers)	/* state 106 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x400, 0x8400 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(106);
    switch (_Types_symbol) {
    case structsym_value:
      {
        static Int my_followers[] = { 0x0, 0x400, 0x8400 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88(_followers);
        break;
      }
    case hole_struct_type_value: HOLE_ACTION (0, "struct_type");
    case struct_type_value:
      {
        n = Parse_state_106(followers);
        break;
      }
    case hole_OPTMORE_struct_type_value: HOLE_ACTION (0, "List_struct_type");
    case OPTMORE_struct_type_value:
      {
        n = Parse_state_107();
        break;
      }
    default:
    /* default item:OPTMORE_struct_type  ->  struct_type . OPTMORE_struct_type      followers: closechainspacesubsemicolonsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_struct_type);
      _Types_symbol = OPTMORE_struct_type_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_108 (void)	/* state 108 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_109();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 111
   hole_OPTMORE_field hole_field hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym closechainsym 
 */
static int Parse_state_111 (SymbolSet followers)	/* state 111 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x2100, 0x0, 0xb84000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(111);
    switch (_Types_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x2100, 0x8000, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        static Int my_followers[] = { 0x2100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_95(_followers);
        break;
      }
    case hole_ALT_TypeName_SEP__sym_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP__sym_value:
      {
        static Int my_followers[] = { 0x2100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_98();
        break;
      }
    case hole_TypeNames_value: HOLE_ACTION (0, "List_TypeName");
    case TypeNames_value:
      {
        static Int my_followers[] = { 0x2100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_99(_followers);
        break;
      }
    case hole_field_value: HOLE_ACTION (0, "field");
    case field_value:
      {
        static Int my_followers[] = { 0x2000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_102(_followers);
        break;
      }
    case hole_OPTMORE_field_value: HOLE_ACTION (0, "List_field");
    case OPTMORE_field_value:
      {
        n = Parse_state_112(followers);
        break;
      }
    default:
    /* default item:struct_type  ->  structsym s_sym Identsym openchainsym OPT_Identsym__USER_FIELDSsym OPTMORE_field OPT_sub_union . OPTMORE_field closechainsym OPT_Identsym semicolonsym followers: hole_OPTMORE_macro hole_macro hashdefinesym hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_struct_type hole_struct_type structsym closechainspacesubsemicolonsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_field);
      _Types_symbol = OPTMORE_field_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 112
   closechainsym 
 */
static int Parse_state_112 (SymbolSet followers)	/* state 112 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_113(followers);
      }
  return n-1;
}

/* directors of state 113
   Identsym semicolonsym 
 */
static int Parse_state_113 (SymbolSet followers)	/* state 113 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x4100, 0x0, 0x0 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(113);
    switch (_Types_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x4000, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_114();
        break;
      }
    case OPT_Identsym_value:
      {
        n = Parse_state_115();
        break;
      }
    default:
    /* default item:struct_type  ->  structsym s_sym Identsym openchainsym OPT_Identsym__USER_FIELDSsym OPTMORE_field OPT_sub_union OPTMORE_field closechainsym . OPT_Identsym semicolonsym followers: hole_OPTMORE_macro hole_macro hashdefinesym hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_struct_type hole_struct_type structsym closechainspacesubsemicolonsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Ident,0,Ident);
      _Types_symbol = OPT_Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

static int Parse_state_115 (void)	/* state 115 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_116();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 117
   hole_OPTMORE_macro hole_macro hashdefinesym hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym 
 */
static int Parse_state_117 (SymbolSet followers)	/* state 117 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x404100, 0x441800 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(117);
    switch (_Types_symbol) {
    case hashdefinesym_value:
      {
        static Int my_followers[] = { 0x0, 0x404100, 0x441800 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_118(_followers);
        break;
      }
    case hole_macro_value: HOLE_ACTION (0, "macro");
    case macro_value:
      {
        static Int my_followers[] = { 0x0, 0x400100, 0x401000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_138(_followers);
        break;
      }
    case hole_OPTMORE_macro_value: HOLE_ACTION (0, "List_macro");
    case OPTMORE_macro_value:
      {
        n = Parse_state_140(followers);
        break;
      }
    default:
    /* default item:StructType  ->  hashifndefspaceDEFunderscoreSTRUCTunderscoresym Identsym hashdefinespaceDEFunderscoreSTRUCTunderscoresym Identsym struct_type . OPTMORE_macro OPTMORE_CreateFunction hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym Identsym spacestarslashsym    followers: hole_OPTMORE_StructType hole_StructType hashifndefspaceDEFunderscoreSTRUCTunderscoresym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_macro);
      _Types_symbol = OPTMORE_macro_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 118
   Identsym 
 */
static int Parse_state_118 (SymbolSet followers)	/* state 118 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_119(followers);
      }
  return n-1;
}

/* directors of state 119
   _sym 
 */
static int Parse_state_119 (SymbolSet followers)	/* state 119 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_120(followers);
      }
  return n-1;
}

/* directors of state 120
   Identsym 
 */
static int Parse_state_120 (SymbolSet followers)	/* state 120 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_121(followers);
      }
  return n-1;
}

/* directors of state 121
   openparunderscorepcloseparsym 
 */
static int Parse_state_121 (SymbolSet followers)	/* state 121 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_122(followers);
      }
  return n-1;
}

/* directors of state 122
   openparsym 
 */
static int Parse_state_122 (SymbolSet followers)	/* state 122 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_123(followers);
      }
  return n-1;
}

/* directors of state 123
   Identsym openparstarunderscorepcloseparsym 
 */
static int Parse_state_123 (SymbolSet followers)	/* state 123 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x40000, 0x0 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(123);
    switch (_Types_symbol) {
    case openparstarunderscorepcloseparsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_124(followers);
        break;
      }
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_132(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:macro  ->  hashdefinesym Identsym _sym Identsym openparunderscorepcloseparsym openparsym . openparstarunderscorepcloseparsym OPTMORE_dotsubdotsym_Identsym dotsym Identsym closeparsym  followers: hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_macro hole_macro hashdefinesym Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "openparstarunderscorepcloseparsym expected");
      dont_shift = TRUE; _Types_symbol = openparstarunderscorepcloseparsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 124
   hole_OPTMORE_dotsubdotsym_Identsym dotsubdotsym dotsym 
 */
static int Parse_state_124 (SymbolSet followers)	/* state 124 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x8080000, 0x20000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(124);
    switch (_Types_symbol) {
    case dotsubdotsym_value:
      {
        static Int my_followers[] = { 0x0, 0x80000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_125(_followers);
        break;
      }
    case hole_OPTMORE_dotsubdotsym_Identsym_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_dotsubdotsym_Identsym_value:
      {
        n = Parse_state_128(followers);
        break;
      }
    default:
    /* default item:macro  ->  hashdefinesym Identsym _sym Identsym openparunderscorepcloseparsym openparsym openparstarunderscorepcloseparsym . OPTMORE_dotsubdotsym_Identsym dotsym Identsym closeparsym  followers: hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_macro hole_macro hashdefinesym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _Types_symbol = OPTMORE_dotsubdotsym_Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 125
   Identsym 
 */
static int Parse_state_125 (SymbolSet followers)	/* state 125 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_126(followers);
      }
  return n-1;
}

/* directors of state 126
   hole_OPTMORE_dotsubdotsym_Identsym dotsubdotsym 
 */
static int Parse_state_126 (SymbolSet followers)	/* state 126 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x8000000, 0x20000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(126);
    switch (_Types_symbol) {
    case dotsubdotsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_125(followers);
        break;
      }
    case hole_OPTMORE_dotsubdotsym_Identsym_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_dotsubdotsym_Identsym_value:
      {
        n = Parse_state_127();
        break;
      }
    default:
    /* default item:OPTMORE_dotsubdotsym_Identsym  ->  dotsubdotsym Identsym . OPTMORE_dotsubdotsym_Identsym        followers: dotsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _Types_symbol = OPTMORE_dotsubdotsym_Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 128
   dotsym 
 */
static int Parse_state_128 (SymbolSet followers)	/* state 128 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_129(followers);
      }
  return n-1;
}

/* directors of state 129
   Identsym 
 */
static int Parse_state_129 (SymbolSet followers)	/* state 129 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_130();
      }
  return n-1;
}

static int Parse_state_130 (void)	/* state 130 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_131();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 132
   underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym 
 */
static int Parse_state_132 (SymbolSet followers)	/* state 132 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_133(followers);
      }
  return n-1;
}

/* directors of state 133
   hole_OPTMORE_dotsubdotsym_Identsym dotsubdotsym dotsym 
 */
static int Parse_state_133 (SymbolSet followers)	/* state 133 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x8080000, 0x20000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(133);
    switch (_Types_symbol) {
    case dotsubdotsym_value:
      {
        static Int my_followers[] = { 0x0, 0x80000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_125(_followers);
        break;
      }
    case hole_OPTMORE_dotsubdotsym_Identsym_value: HOLE_ACTION (0, "List_Ident");
    case OPTMORE_dotsubdotsym_Identsym_value:
      {
        n = Parse_state_134(followers);
        break;
      }
    default:
    /* default item:macro  ->  hashdefinesym Identsym _sym Identsym openparunderscorepcloseparsym openparsym Identsym underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym . OPTMORE_dotsubdotsym_Identsym dotsym Identsym closeparsym       followers: hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_macro hole_macro hashdefinesym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Ident);
      _Types_symbol = OPTMORE_dotsubdotsym_Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 134
   dotsym 
 */
static int Parse_state_134 (SymbolSet followers)	/* state 134 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_135(followers);
      }
  return n-1;
}

/* directors of state 135
   Identsym 
 */
static int Parse_state_135 (SymbolSet followers)	/* state 135 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_136();
      }
  return n-1;
}

static int Parse_state_136 (void)	/* state 136 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_137();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 138
   hole_OPTMORE_macro hole_macro hashdefinesym 
 */
static int Parse_state_138 (SymbolSet followers)	/* state 138 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x4000, 0x40800 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(138);
    switch (_Types_symbol) {
    case hashdefinesym_value:
      {
        static Int my_followers[] = { 0x0, 0x4000, 0x40800 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_118(_followers);
        break;
      }
    case hole_macro_value: HOLE_ACTION (0, "macro");
    case macro_value:
      {
        n = Parse_state_138(followers);
        break;
      }
    case hole_OPTMORE_macro_value: HOLE_ACTION (0, "List_macro");
    case OPTMORE_macro_value:
      {
        n = Parse_state_139();
        break;
      }
    default:
    /* default item:OPTMORE_macro  ->  macro . OPTMORE_macro        followers: hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_macro);
      _Types_symbol = OPTMORE_macro_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 140
   hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym 
 */
static int Parse_state_140 (SymbolSet followers)	/* state 140 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x400100, 0x401000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(140);
    switch (_Types_symbol) {
    case CREATEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x400100, 0x401000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_141(_followers);
        break;
      }
    case hole_CreateFunction_value: HOLE_ACTION (0, "CreateFunction");
    case CreateFunction_value:
      {
        static Int my_followers[] = { 0x0, 0x100, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_143(_followers);
        break;
      }
    case hole_OPTMORE_CreateFunction_value: HOLE_ACTION (0, "List_CreateFunction");
    case OPTMORE_CreateFunction_value:
      {
        n = Parse_state_145(followers);
        break;
      }
    default:
    /* default item:StructType  ->  hashifndefspaceDEFunderscoreSTRUCTunderscoresym Identsym hashdefinespaceDEFunderscoreSTRUCTunderscoresym Identsym struct_type OPTMORE_macro . OPTMORE_CreateFunction hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym Identsym spacestarslashsym    followers: hole_OPTMORE_StructType hole_StructType hashifndefspaceDEFunderscoreSTRUCTunderscoresym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_CreateFunction);
      _Types_symbol = OPTMORE_CreateFunction_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 141
   hole_OPTMORE_field hole_field hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym 
 */
static int Parse_state_141 (SymbolSet followers)	/* state 141 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0xb84000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(141);
    switch (_Types_symbol) {
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100, 0x8000, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_95(_followers);
        break;
      }
    case hole_ALT_TypeName_SEP__sym_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP__sym_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_98();
        break;
      }
    case hole_TypeNames_value: HOLE_ACTION (0, "List_TypeName");
    case TypeNames_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_99(_followers);
        break;
      }
    case hole_field_value: HOLE_ACTION (0, "field");
    case field_value:
      {
        n = Parse_state_102(followers);
        break;
      }
    case hole_OPTMORE_field_value: HOLE_ACTION (0, "List_field");
    case OPTMORE_field_value:
      {
        n = Parse_state_142();
        break;
      }
    default:
    /* default item:CreateFunction  ->  CREATEsym . OPTMORE_field   followers: hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_field);
      _Types_symbol = OPTMORE_field_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 143
   hole_OPTMORE_CreateFunction hole_CreateFunction CREATEsym 
 */
static int Parse_state_143 (SymbolSet followers)	/* state 143 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x400000, 0x401000 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(143);
    switch (_Types_symbol) {
    case CREATEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x400000, 0x401000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_141(_followers);
        break;
      }
    case hole_CreateFunction_value: HOLE_ACTION (0, "CreateFunction");
    case CreateFunction_value:
      {
        n = Parse_state_143(followers);
        break;
      }
    case hole_OPTMORE_CreateFunction_value: HOLE_ACTION (0, "List_CreateFunction");
    case OPTMORE_CreateFunction_value:
      {
        n = Parse_state_144();
        break;
      }
    default:
    /* default item:OPTMORE_CreateFunction  ->  CreateFunction . OPTMORE_CreateFunction     followers: hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_CreateFunction);
      _Types_symbol = OPTMORE_CreateFunction_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 145
   hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym 
 */
static int Parse_state_145 (SymbolSet followers)	/* state 145 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_146(followers);
      }
  return n-1;
}

/* directors of state 146
   Identsym 
 */
static int Parse_state_146 (SymbolSet followers)	/* state 146 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_147();
      }
  return n-1;
}

static int Parse_state_147 (void)	/* state 147 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_148();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 149
   hole_OPTMORE_StructType hole_StructType hashifndefspaceDEFunderscoreSTRUCTunderscoresym 
 */
static int Parse_state_149 (SymbolSet followers)	/* state 149 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x40, 0x2002 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(149);
    switch (_Types_symbol) {
    case hashifndefspaceDEFunderscoreSTRUCTunderscoresym_value:
      {
        static Int my_followers[] = { 0x0, 0x40, 0x2002 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84(_followers);
        break;
      }
    case hole_StructType_value: HOLE_ACTION (0, "StructType");
    case StructType_value:
      {
        n = Parse_state_149(followers);
        break;
      }
    case hole_OPTMORE_StructType_value: HOLE_ACTION (0, "List_StructType");
    case OPTMORE_StructType_value:
      {
        n = Parse_state_150();
        break;
      }
    default:
    /* default item:OPTMORE_StructType  ->  StructType . OPTMORE_StructType followers: Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_StructType);
      _Types_symbol = OPTMORE_StructType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 151
   hashincludespacelessthanstdargdothgreaterthansym 
 */
Types_Types Parse_state_Types_Types (void)	/* state 151 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x2, 0x0, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(151);
    switch (_Types_symbol) {
    case Types_value:
      n = 1; break; /* accept Types  ->  . includes1 OPTMORE_EnumType OPTMORE_PointerType OPTMORE_subtypedef includes2 OPTMORE_subtypedef OPTMORE_BindType RootDecl OPTMORE_StructType        followers: Types_EOF  */
    case hashincludespacelessthanstdargdothgreaterthansym_value:
      {
        static Int my_followers[] = { 0x40000410, 0xf0000008, 0x320 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_152();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        break;
      }
    case includes1_value:
      {
        n = Parse_state_155(followers);
        break;
      }
    default:
    /* default item:Types  ->  . includes1 OPTMORE_EnumType OPTMORE_PointerType OPTMORE_subtypedef includes2 OPTMORE_subtypedef OPTMORE_BindType RootDecl OPTMORE_StructType   followers: Types_EOF  */
/* nt = 0x822b028 */
      n = 0; _Types_symbol = includes1_value;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_Types")->sub.PointerValue;
}

static int Parse_state_152 (void)	/* state 152 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_153();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

static int Parse_state_153 (void)	/* state 153 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_154();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 155
   hole_OPTMORE_EnumType hole_EnumType typedefsym hole_OPTMORE_PointerType hole_PointerType hashifndefspaceDEFunderscoreTYPEunderscoresym hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_includes2 hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym 
 */
static int Parse_state_155 (SymbolSet followers)	/* state 155 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x40000410, 0xf0000008, 0x320 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(155);
    switch (_Types_symbol) {
    case typedefsym_value:
      {
        static Int my_followers[] = { 0x40000410, 0xf0000008, 0x320 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(_followers);
        break;
      }
    case hole_EnumType_value: HOLE_ACTION (0, "EnumType");
    case EnumType_value:
      {
        static Int my_followers[] = { 0x40000010, 0xe0000008, 0x300 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_19(_followers);
        break;
      }
    case hole_OPTMORE_EnumType_value: HOLE_ACTION (0, "List_EnumType");
    case OPTMORE_EnumType_value:
      {
        n = Parse_state_156(followers);
        break;
      }
    default:
    /* default item:Types  ->  includes1 . OPTMORE_EnumType OPTMORE_PointerType OPTMORE_subtypedef includes2 OPTMORE_subtypedef OPTMORE_BindType RootDecl OPTMORE_StructType        followers: Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_EnumType);
      _Types_symbol = OPTMORE_EnumType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 156
   hole_OPTMORE_PointerType hole_PointerType hashifndefspaceDEFunderscoreTYPEunderscoresym hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_includes2 hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym 
 */
static int Parse_state_156 (SymbolSet followers)	/* state 156 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x40000010, 0xe0000008, 0x300 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(156);
    switch (_Types_symbol) {
    case hashifndefspaceDEFunderscoreTYPEunderscoresym_value:
      {
        static Int my_followers[] = { 0x40000010, 0xe0000008, 0x300 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_22(_followers);
        break;
      }
    case hole_PointerType_value: HOLE_ACTION (0, "PointerType");
    case PointerType_value:
      {
        static Int my_followers[] = { 0x10, 0xc0000008, 0x200 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_39(_followers);
        break;
      }
    case hole_OPTMORE_PointerType_value: HOLE_ACTION (0, "List_PointerType");
    case OPTMORE_PointerType_value:
      {
        n = Parse_state_157(followers);
        break;
      }
    default:
    /* default item:Types  ->  includes1 OPTMORE_EnumType . OPTMORE_PointerType OPTMORE_subtypedef includes2 OPTMORE_subtypedef OPTMORE_BindType RootDecl OPTMORE_StructType        followers: Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_PointerType);
      _Types_symbol = OPTMORE_PointerType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 157
   hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_includes2 hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym 
 */
static int Parse_state_157 (SymbolSet followers)	/* state 157 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x10, 0xc0000008, 0x200 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(157);
    switch (_Types_symbol) {
    case typedefspacesym_value:
      {
        static Int my_followers[] = { 0x10, 0xc0000008, 0x200 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(_followers);
        break;
      }
    case hole_subtypedef_value: HOLE_ACTION (0, "subtypedef");
    case subtypedef_value:
      {
        static Int my_followers[] = { 0x10, 0x80000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_35(_followers);
        break;
      }
    case hole_OPTMORE_subtypedef_value: HOLE_ACTION (0, "List_subtypedef");
    case OPTMORE_subtypedef_value:
      {
        n = Parse_state_158(followers);
        break;
      }
    default:
    /* default item:Types  ->  includes1 OPTMORE_EnumType OPTMORE_PointerType . OPTMORE_subtypedef includes2 OPTMORE_subtypedef OPTMORE_BindType RootDecl OPTMORE_StructType        followers: Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_subtypedef);
      _Types_symbol = OPTMORE_subtypedef_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 158
   hole_includes2 hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym 
 */
static int Parse_state_158 (SymbolSet followers)	/* state 158 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x10, 0x80000000, 0x0 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(158);
    switch (_Types_symbol) {
    case hashincludespacelessthanfrontslashscanunderscoresupportdothgreaterthansym_value:
      {
        static Int my_followers[] = { 0x80000, 0x40000018, 0x281 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_43(_followers);
        break;
      }
    case hole_includes2_value: HOLE_ACTION (0, "includes2");
    case includes2_value:
      {
        n = Parse_state_159(followers);
        break;
      }
    default:
    /* default item:Types  ->  includes1 OPTMORE_EnumType OPTMORE_PointerType OPTMORE_subtypedef . includes2 OPTMORE_subtypedef OPTMORE_BindType RootDecl OPTMORE_StructType        followers: Types_EOF  */
/* nt = 0x822c558 */
      InputError (SCAN_POSITION, TRUE, "includes2 expected");
      PUSH_PARSEVALUE(Pointer,0,Types_includes2);
      _Types_symbol = includes2_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 159
   hole_OPTMORE_subtypedef hole_subtypedef typedefspacesym hole_OPTMORE_BindType hole_BindType typedefspaceBindspaceBindunderscoresym externsym 
 */
static int Parse_state_159 (SymbolSet followers)	/* state 159 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x80000, 0x40000018, 0x281 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(159);
    switch (_Types_symbol) {
    case typedefspacesym_value:
      {
        static Int my_followers[] = { 0x80000, 0x40000018, 0x281 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(_followers);
        break;
      }
    case hole_subtypedef_value: HOLE_ACTION (0, "subtypedef");
    case subtypedef_value:
      {
        static Int my_followers[] = { 0x80000, 0x10, 0x81 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_35(_followers);
        break;
      }
    case hole_OPTMORE_subtypedef_value: HOLE_ACTION (0, "List_subtypedef");
    case OPTMORE_subtypedef_value:
      {
        n = Parse_state_160(followers);
        break;
      }
    default:
    /* default item:Types  ->  includes1 OPTMORE_EnumType OPTMORE_PointerType OPTMORE_subtypedef includes2 . OPTMORE_subtypedef OPTMORE_BindType RootDecl OPTMORE_StructType        followers: Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_subtypedef);
      _Types_symbol = OPTMORE_subtypedef_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 160
   hole_OPTMORE_BindType hole_BindType typedefspaceBindspaceBindunderscoresym externsym 
 */
static int Parse_state_160 (SymbolSet followers)	/* state 160 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x80000, 0x10, 0x81 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(160);
    switch (_Types_symbol) {
    case typedefspaceBindspaceBindunderscoresym_value:
      {
        static Int my_followers[] = { 0x80000, 0x10, 0x81 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_59(_followers);
        break;
      }
    case hole_BindType_value: HOLE_ACTION (0, "BindType");
    case BindType_value:
      {
        static Int my_followers[] = { 0x0, 0x10, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_81(_followers);
        break;
      }
    case hole_OPTMORE_BindType_value: HOLE_ACTION (0, "List_BindType");
    case OPTMORE_BindType_value:
      {
        n = Parse_state_161(followers);
        break;
      }
    default:
    /* default item:Types  ->  includes1 OPTMORE_EnumType OPTMORE_PointerType OPTMORE_subtypedef includes2 OPTMORE_subtypedef . OPTMORE_BindType RootDecl OPTMORE_StructType        followers: Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_BindType);
      _Types_symbol = OPTMORE_BindType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 161
   externsym 
 */
static int Parse_state_161 (SymbolSet followers)	/* state 161 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x10, 0x0 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(161);
    switch (_Types_symbol) {
    case externsym_value:
      {
        static Int my_followers[] = { 0x0, 0x40, 0x2002 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_162(_followers);
        break;
      }
    case RootDecl_value:
      {
        n = Parse_state_166(followers);
        break;
      }
    default:
    /* default item:Types  ->  includes1 OPTMORE_EnumType OPTMORE_PointerType OPTMORE_subtypedef includes2 OPTMORE_subtypedef OPTMORE_BindType . RootDecl OPTMORE_StructType        followers: Types_EOF  */
/* nt = 0x82331e0 */
      InputError (SCAN_POSITION, TRUE, "RootDecl expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      PUSH_PARSEVALUE(Ident,0,Ident);
      _Types_symbol = RootDecl_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 162
   Identsym 
 */
static int Parse_state_162 (SymbolSet followers)	/* state 162 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_163(followers);
      }
  return n-1;
}

/* directors of state 163
   Identsym 
 */
static int Parse_state_163 (SymbolSet followers)	/* state 163 */
{ int n;
  Bool dont_shift = FALSE;
  NOT_USED(followers);
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_164();
      }
  return n-1;
}

static int Parse_state_164 (void)	/* state 164 */
{ int n;
  Bool dont_shift = FALSE;
      {
        n = Parse_state_165();
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
      }
  return n-1;
}

/* directors of state 166
   hole_OPTMORE_StructType hole_StructType hashifndefspaceDEFunderscoreSTRUCTunderscoresym 
 */
static int Parse_state_166 (SymbolSet followers)	/* state 166 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x40, 0x2002 };
  Int _followers[3];
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(166);
    switch (_Types_symbol) {
    case hashifndefspaceDEFunderscoreSTRUCTunderscoresym_value:
      {
        static Int my_followers[] = { 0x0, 0x40, 0x2002 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84(_followers);
        break;
      }
    case hole_StructType_value: HOLE_ACTION (0, "StructType");
    case StructType_value:
      {
        n = Parse_state_149(followers);
        break;
      }
    case hole_OPTMORE_StructType_value: HOLE_ACTION (0, "List_StructType");
    case OPTMORE_StructType_value:
      {
        n = Parse_state_167();
        break;
      }
    default:
    /* default item:Types  ->  includes1 OPTMORE_EnumType OPTMORE_PointerType OPTMORE_subtypedef includes2 OPTMORE_subtypedef OPTMORE_BindType RootDecl . OPTMORE_StructType        followers: Types_EOF  */
/* nt = (nil) */
      PUSH_PARSEVALUE(Pointer,0,List_Types_StructType);
      _Types_symbol = OPTMORE_StructType_value; n = 0;
      break;
    }
  } while (n==0);
  return n-1;
}

/* directors of state 168
   hashincludespacebackslashdoublequotesym 
 */
List_Ident Parse_state_Types_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym (void)	/* state 168 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x80, 0x0, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(168);
    switch (_Types_symbol) {
    case OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value:
      n = 1; break; /* accept OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym  ->  . hashincludespacebackslashdoublequotesym Identsym dothbackslashdoublequotesym OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym   followers: Types_EOF  */
    case hashincludespacebackslashdoublequotesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_53(followers);
        break;
      }
    default:
    /* default item:OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym  ->  .        followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Ident")->sub.PointerValue;
}

/* directors of state 169
   hole_ALT_TypeName_SEP_commasym_NL hole_TypeName Identsym 
 */
List_Types_TypeName Parse_state_Types_Enums (void)	/* state 169 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0x200040 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(169);
    switch (_Types_symbol) {
    case Enums_value:
      n = 1; break; /* accept Enums  ->  . ALT_TypeName_SEP_commasym_NL       followers: Types_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        n = Parse_state_5(followers);
        break;
      }
    case hole_ALT_TypeName_SEP_commasym_NL_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP_commasym_NL_value:
      {
        n = Parse_state_8();
        break;
      }
    default:
    /* default item:Enums  ->  . ALT_TypeName_SEP_commasym_NL  followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_TypeName_SEP_commasym_NL expected");
      PUSH_PARSEVALUE(Pointer,0,List_Types_TypeName);
      _Types_symbol = ALT_TypeName_SEP_commasym_NL_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_TypeName")->sub.PointerValue;
}

/* directors of state 170
   typedefsym 
 */
Types_EnumType Parse_state_Types_EnumType (void)	/* state 170 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x400, 0x0, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(170);
    switch (_Types_symbol) {
    case EnumType_value:
      n = 1; break; /* accept EnumType  ->  . typedefsym enumsym openchainsym Enums closechainsym Identsym semicolonsym externspacecharspacestarsym Identsym underscorenamesopenbrkclosebrksemicolonsym hashdefinespaceNUMunderscoresym Identsym Intsym       followers: Types_EOF  */
    case typedefsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_1(followers);
        break;
      }
    default:
    /* default item:EnumType  ->  . typedefsym enumsym openchainsym Enums closechainsym Identsym semicolonsym externspacecharspacestarsym Identsym underscorenamesopenbrkclosebrksemicolonsym hashdefinespaceNUMunderscoresym Identsym Intsym  followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "typedefsym expected");
      dont_shift = TRUE; _Types_symbol = typedefsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_EnumType")->sub.PointerValue;
}

/* directors of state 171
   hole_TypeName Identsym 
 */
List_Types_TypeName Parse_state_Types_ALT_TypeName_SEP_commasym_NL (void)	/* state 171 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0x200000 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(171);
    switch (_Types_symbol) {
    case ALT_TypeName_SEP_commasym_NL_value:
      n = 1; break; /* accept ALT_TypeName_SEP_commasym_NL  ->  . TypeName commasym ALT_TypeName_SEP_commasym_NL      followers: Types_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x2000000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        n = Parse_state_5(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_TypeName_SEP_commasym_NL  ->  . TypeName       followers: Types_EOF  */
/* nt = 0x823dca0 */
      InputError (SCAN_POSITION, TRUE, "TypeName expected");
      PUSH_PARSEVALUE(Pointer,0,Types_TypeName);
      _Types_symbol = TypeName_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_TypeName")->sub.PointerValue;
}

/* directors of state 172
   typedefspaceBindspaceBindunderscoresym 
 */
Types_BindType Parse_state_Types_BindType (void)	/* state 172 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x80000, 0x0, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(172);
    switch (_Types_symbol) {
    case BindType_value:
      n = 1; break; /* accept BindType  ->  . typedefspaceBindspaceBindunderscoresym Identsym semicolonsym typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym Identsym semicolonsym hashdefinespaceListunderscoreBindunderscoresym Identsym underscoredataopenparxcloseparsym openparBindunderscoresym Identsym closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym hashdefinespaceListunderscoreBindunderscoresym Identsym underscorenextopenparxcloseparsym openparListunderscoreBindunderscoresym Identsym closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym hashdefinespaceBindunderscoresym Identsym _kindsym Intsym       followers: Types_EOF  */
    case typedefspaceBindspaceBindunderscoresym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_59(followers);
        break;
      }
    default:
    /* default item:BindType  ->  . typedefspaceBindspaceBindunderscoresym Identsym semicolonsym typedefspaceListunderscoreBindspaceListunderscoreBindunderscoresym Identsym semicolonsym hashdefinespaceListunderscoreBindunderscoresym Identsym underscoredataopenparxcloseparsym openparBindunderscoresym Identsym closeparFrontunderscoreListunderscoredataopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym hashdefinespaceListunderscoreBindunderscoresym Identsym underscorenextopenparxcloseparsym openparListunderscoreBindunderscoresym Identsym closeparFrontunderscoreListunderscorenextopenparopenparFrontunderscoreListcloseparopenparxcloseparcloseparsym hashdefinespaceBindunderscoresym Identsym _kindsym Intsym  followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "typedefspaceBindspaceBindunderscoresym expected");
      dont_shift = TRUE; _Types_symbol = typedefspaceBindspaceBindunderscoresym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_BindType")->sub.PointerValue;
}

/* directors of state 173
   hashifndefspaceDEFunderscoreTYPEunderscoresym 
 */
Types_PointerType Parse_state_Types_PointerType (void)	/* state 173 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x40000000, 0x0, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(173);
    switch (_Types_symbol) {
    case PointerType_value:
      n = 1; break; /* accept PointerType  ->  . hashifndefspaceDEFunderscoreTYPEunderscoresym Identsym hashdefinespaceDEFunderscoreTYPEunderscoresym Identsym typedefspacestructspacesunderscoresym Identsym starsym Identsym semicolonsym OPTMORE_subtypedef hashendifsym   followers: Types_EOF  */
    case hashifndefspaceDEFunderscoreTYPEunderscoresym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_22(followers);
        break;
      }
    default:
    /* default item:PointerType  ->  . hashifndefspaceDEFunderscoreTYPEunderscoresym Identsym hashdefinespaceDEFunderscoreTYPEunderscoresym Identsym typedefspacestructspacesunderscoresym Identsym starsym Identsym semicolonsym OPTMORE_subtypedef hashendifsym      followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "hashifndefspaceDEFunderscoreTYPEunderscoresym expected");
      dont_shift = TRUE; _Types_symbol = hashifndefspaceDEFunderscoreTYPEunderscoresym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_PointerType")->sub.PointerValue;
}

/* directors of state 174
   typedefspacesym 
 */
Types_subtypedef Parse_state_Types_subtypedef (void)	/* state 174 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x8, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(174);
    switch (_Types_symbol) {
    case subtypedef_value:
      n = 1; break; /* accept subtypedef  ->  . typedefspacesym Identsym Identsym semicolonsym        followers: Types_EOF  */
    case typedefspacesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_31(followers);
        break;
      }
    default:
    /* default item:subtypedef  ->  . typedefspacesym Identsym Identsym semicolonsym   followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "typedefspacesym expected");
      dont_shift = TRUE; _Types_symbol = typedefspacesym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_subtypedef")->sub.PointerValue;
}

/* directors of state 175
   structsym 
 */
Types_struct_type Parse_state_Types_struct_type (void)	/* state 175 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x400, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(175);
    switch (_Types_symbol) {
    case struct_type_value:
      n = 1; break; /* accept struct_type  ->  . structsym s_sym Identsym openchainsym OPT_Identsym__USER_FIELDSsym OPTMORE_field OPT_sub_union OPTMORE_field closechainsym OPT_Identsym semicolonsym followers: Types_EOF  */
    case structsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88(followers);
        break;
      }
    default:
    /* default item:struct_type  ->  . structsym s_sym Identsym openchainsym OPT_Identsym__USER_FIELDSsym OPTMORE_field OPT_sub_union OPTMORE_field closechainsym OPT_Identsym semicolonsym    followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "structsym expected");
      dont_shift = TRUE; _Types_symbol = structsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_struct_type")->sub.PointerValue;
}

/* directors of state 176
   hole_macro hashdefinesym 
 */
List_Types_macro Parse_state_Types_OPTMORE_macro (void)	/* state 176 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x4000, 0x40000 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(176);
    switch (_Types_symbol) {
    case OPTMORE_macro_value:
      n = 1; break; /* accept OPTMORE_macro  ->  . macro OPTMORE_macro        followers: Types_EOF  */
    case hashdefinesym_value:
      {
        static Int my_followers[] = { 0x0, 0x4000, 0x40800 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_118(_followers);
        break;
      }
    case hole_macro_value: HOLE_ACTION (0, "macro");
    case macro_value:
      {
        n = Parse_state_138(followers);
        break;
      }
    default:
    /* default item:OPTMORE_macro  ->  .       followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_macro_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Types_macro);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_macro")->sub.PointerValue;
}

/* directors of state 177
   hole_CreateFunction CREATEsym 
 */
List_Types_CreateFunction Parse_state_Types_OPTMORE_CreateFunction (void)	/* state 177 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x400000, 0x400000 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(177);
    switch (_Types_symbol) {
    case OPTMORE_CreateFunction_value:
      n = 1; break; /* accept OPTMORE_CreateFunction  ->  . CreateFunction OPTMORE_CreateFunction     followers: Types_EOF  */
    case CREATEsym_value:
      {
        static Int my_followers[] = { 0x0, 0x400000, 0x401000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_141(_followers);
        break;
      }
    case hole_CreateFunction_value: HOLE_ACTION (0, "CreateFunction");
    case CreateFunction_value:
      {
        n = Parse_state_143(followers);
        break;
      }
    default:
    /* default item:OPTMORE_CreateFunction  ->  .      followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_CreateFunction_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Types_CreateFunction);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_CreateFunction")->sub.PointerValue;
}

/* directors of state 178
   hashifndefspaceDEFunderscoreSTRUCTunderscoresym 
 */
Types_StructType Parse_state_Types_StructType (void)	/* state 178 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x40, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(178);
    switch (_Types_symbol) {
    case StructType_value:
      n = 1; break; /* accept StructType  ->  . hashifndefspaceDEFunderscoreSTRUCTunderscoresym Identsym hashdefinespaceDEFunderscoreSTRUCTunderscoresym Identsym struct_type OPTMORE_macro OPTMORE_CreateFunction hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym Identsym spacestarslashsym    followers: Types_EOF  */
    case hashifndefspaceDEFunderscoreSTRUCTunderscoresym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_84(followers);
        break;
      }
    default:
    /* default item:StructType  ->  . hashifndefspaceDEFunderscoreSTRUCTunderscoresym Identsym hashdefinespaceDEFunderscoreSTRUCTunderscoresym Identsym struct_type OPTMORE_macro OPTMORE_CreateFunction hashendifspaceslashstarspaceDEFunderscoreSTRUCTunderscoresym Identsym spacestarslashsym       followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "hashifndefspaceDEFunderscoreSTRUCTunderscoresym expected");
      dont_shift = TRUE; _Types_symbol = hashifndefspaceDEFunderscoreSTRUCTunderscoresym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_StructType")->sub.PointerValue;
}

/* directors of state 179
   hole_field hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym 
 */
List_Types_field Parse_state_Types_OPTMORE_field (void)	/* state 179 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0xb80000 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(179);
    switch (_Types_symbol) {
    case OPTMORE_field_value:
      n = 1; break; /* accept OPTMORE_field  ->  . field OPTMORE_field        followers: Types_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100, 0x8000, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_95(_followers);
        break;
      }
    case hole_ALT_TypeName_SEP__sym_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP__sym_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_98();
        break;
      }
    case hole_TypeNames_value: HOLE_ACTION (0, "List_TypeName");
    case TypeNames_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0xb84000 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_99(_followers);
        break;
      }
    case hole_field_value: HOLE_ACTION (0, "field");
    case field_value:
      {
        n = Parse_state_102(followers);
        break;
      }
    default:
    /* default item:OPTMORE_field  ->  .       followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_field_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Types_field);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_field")->sub.PointerValue;
}

/* directors of state 180
   hole_struct_type structsym 
 */
List_Types_struct_type Parse_state_Types_OPTMORE_struct_type (void)	/* state 180 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x400, 0x400 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(180);
    switch (_Types_symbol) {
    case OPTMORE_struct_type_value:
      n = 1; break; /* accept OPTMORE_struct_type  ->  . struct_type OPTMORE_struct_type      followers: Types_EOF  */
    case structsym_value:
      {
        static Int my_followers[] = { 0x0, 0x400, 0x8400 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_88(_followers);
        break;
      }
    case hole_struct_type_value: HOLE_ACTION (0, "struct_type");
    case struct_type_value:
      {
        n = Parse_state_106(followers);
        break;
      }
    default:
    /* default item:OPTMORE_struct_type  ->  . followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_struct_type_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Types_struct_type);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_struct_type")->sub.PointerValue;
}

/* directors of state 181
   unionspaceopenchainsym 
 */
List_Types_struct_type Parse_state_Types_sub_union (void)	/* state 181 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x1000, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(181);
    switch (_Types_symbol) {
    case sub_union_value:
      n = 1; break; /* accept sub_union  ->  . unionspaceopenchainsym OPTMORE_struct_type closechainspacesubsemicolonsym      followers: Types_EOF  */
    case unionspaceopenchainsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_105(followers);
        break;
      }
    default:
    /* default item:sub_union  ->  . unionspaceopenchainsym OPTMORE_struct_type closechainspacesubsemicolonsym followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "unionspaceopenchainsym expected");
      dont_shift = TRUE; _Types_symbol = unionspaceopenchainsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_struct_type")->sub.PointerValue;
}

/* directors of state 182
   dotsubdotsym 
 */
List_Ident Parse_state_Types_OPTMORE_dotsubdotsym_Identsym (void)	/* state 182 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x8000000, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(182);
    switch (_Types_symbol) {
    case OPTMORE_dotsubdotsym_Identsym_value:
      n = 1; break; /* accept OPTMORE_dotsubdotsym_Identsym  ->  . dotsubdotsym Identsym OPTMORE_dotsubdotsym_Identsym        followers: Types_EOF  */
    case dotsubdotsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_125(followers);
        break;
      }
    default:
    /* default item:OPTMORE_dotsubdotsym_Identsym  ->  .       followers: Types_EOF  */
      n = 0; _Types_symbol = OPTMORE_dotsubdotsym_Identsym_value;
      { /* optmore action */
        PUSH_PARSEVALUE(Pointer,NULL,List_Ident);
      }
      break;
    }
  } while (n==0);
  return PopParseValue("List_Ident")->sub.PointerValue;
}

/* directors of state 183
   hashdefinesym 
 */
Types_macro Parse_state_Types_macro (void)	/* state 183 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x4000, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(183);
    switch (_Types_symbol) {
    case macro_value:
      n = 1; break; /* accept macro  ->  . hashdefinesym Identsym _sym Identsym openparunderscorepcloseparsym openparsym Identsym underscoreUSERunderscoreACCESSopenparunderscorepcloseparsym OPTMORE_dotsubdotsym_Identsym dotsym Identsym closeparsym       followers: Types_EOF  */
    case hashdefinesym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_118(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:macro  ->  . hashdefinesym Identsym _sym Identsym openparunderscorepcloseparsym openparsym openparstarunderscorepcloseparsym OPTMORE_dotsubdotsym_Identsym dotsym Identsym closeparsym     followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "hashdefinesym expected");
      dont_shift = TRUE; _Types_symbol = hashdefinesym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_macro")->sub.PointerValue;
}

/* directors of state 184
   hole_ALT_TypeName_SEP__sym hole_TypeName Identsym 
 */
List_Types_TypeName Parse_state_Types_TypeNames (void)	/* state 184 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0xa00000 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(184);
    switch (_Types_symbol) {
    case TypeNames_value:
      n = 1; break; /* accept TypeNames  ->  . ALT_TypeName_SEP__sym  followers: Types_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        n = Parse_state_95(followers);
        break;
      }
    case hole_ALT_TypeName_SEP__sym_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP__sym_value:
      {
        n = Parse_state_98();
        break;
      }
    default:
    /* default item:TypeNames  ->  . ALT_TypeName_SEP__sym     followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "ALT_TypeName_SEP__sym expected");
      PUSH_PARSEVALUE(Pointer,0,List_Types_TypeName);
      _Types_symbol = ALT_TypeName_SEP__sym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_TypeName")->sub.PointerValue;
}

/* directors of state 185
   hole_TypeNames hole_ALT_TypeName_SEP__sym hole_TypeName Identsym 
 */
Types_field Parse_state_Types_field (void)	/* state 185 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0xa80000 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(185);
    switch (_Types_symbol) {
    case field_value:
      n = 1; break; /* accept field  ->  . TypeNames Identsym semicolonsym    followers: Types_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x100, 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_95(_followers);
        break;
      }
    case hole_ALT_TypeName_SEP__sym_value: HOLE_ACTION (0, "List_TypeName");
    case ALT_TypeName_SEP__sym_value:
      {
        static Int my_followers[] = { 0x100, 0x0, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        n = Parse_state_98();
        break;
      }
    case hole_TypeNames_value: HOLE_ACTION (0, "List_TypeName");
    case TypeNames_value:
      {
        n = Parse_state_99(followers);
        break;
      }
    default:
    /* default item:field  ->  . TypeNames Identsym semicolonsym       followers: Types_EOF  */
/* nt = 0x823e980 */
      InputError (SCAN_POSITION, TRUE, "TypeNames expected");
      PUSH_PARSEVALUE(Pointer,0,List_Types_TypeName);
      _Types_symbol = TypeNames_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_field")->sub.PointerValue;
}

/* directors of state 186
   Identsym 
 */
Types_TypeName Parse_state_Types_TypeName (void)	/* state 186 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(186);
    switch (_Types_symbol) {
    case TypeName_value:
      n = 1; break; /* accept TypeName  ->  . Identsym        followers: Types_EOF  */
    case Identsym_value:
      {
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    default:
    /* default item:TypeName  ->  . Identsym   followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "Identsym expected");
      PUSH_PARSEVALUE(Ident,0,Ident);
      dont_shift = TRUE; _Types_symbol = Identsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_TypeName")->sub.PointerValue;
}

/* directors of state 187
   CREATEsym 
 */
Types_CreateFunction Parse_state_Types_CreateFunction (void)	/* state 187 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x0, 0x400000, 0x0 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(187);
    switch (_Types_symbol) {
    case CreateFunction_value:
      n = 1; break; /* accept CreateFunction  ->  . CREATEsym OPTMORE_field   followers: Types_EOF  */
    case CREATEsym_value:
      {
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_141(followers);
        break;
      }
    default:
    /* default item:CreateFunction  ->  . CREATEsym OPTMORE_field      followers: Types_EOF  */
/* nt = (nil) */
      InputError (SCAN_POSITION, TRUE, "CREATEsym expected");
      dont_shift = TRUE; _Types_symbol = CREATEsym_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("Types_CreateFunction")->sub.PointerValue;
}

/* directors of state 188
   hole_TypeName Identsym 
 */
List_Types_TypeName Parse_state_Types_ALT_TypeName_SEP__sym (void)	/* state 188 */
{ int n;
  Bool dont_shift = FALSE;
  static Int directors[3] = { 0x100, 0x0, 0x200000 };
  Int _followers[3];
  Int followers[3] = { 0x0, 0x0, 0x1000000 };
  fill_terminal_map();
  SHIFT();
  unite_symbol_sets (_followers, followers, directors, 3);
  DELETE_UNTIL (_followers, Types);
  _Types_symbol = _Types_token;
  do {
    REPORT(188);
    switch (_Types_symbol) {
    case ALT_TypeName_SEP__sym_value:
      n = 1; break; /* accept ALT_TypeName_SEP__sym  ->  . TypeName _sym ALT_TypeName_SEP__sym        followers: Types_EOF  */
    case Identsym_value:
      {
        static Int my_followers[] = { 0x0, 0x8000, 0x0 };
        unite_symbol_sets (_followers, my_followers, followers, 3);
        if (!dont_shift)      PUSH_PARSEVALUE(Ident,Types_lval.Identsym_type,Ident);
        if (!dont_shift) SHIFT(); dont_shift = FALSE;
        n = Parse_state_4();
        break;
      }
    case hole_TypeName_value: HOLE_ACTION (0, "TypeName");
    case TypeName_value:
      {
        n = Parse_state_95(followers);
        break;
      }
    default:
      InputError (SCAN_POSITION, TRUE, "Syntax error");
    /* default item:ALT_TypeName_SEP__sym  ->  . TypeName      followers: Types_EOF  */
/* nt = 0x823dca0 */
      InputError (SCAN_POSITION, TRUE, "TypeName expected");
      PUSH_PARSEVALUE(Pointer,0,Types_TypeName);
      _Types_symbol = TypeName_value; n = 0;
      break;
    }
  } while (n==0);
  return PopParseValue("List_Types_TypeName")->sub.PointerValue;
}

