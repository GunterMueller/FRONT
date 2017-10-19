/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 */
#include <ctype.h>
#include <string.h>

#include <front/front_list.h>
#include <front/mem.h>
#include "flags.h"
#include "GenLex.h"
#include "GenTypes.h"
#include "GenGrammar.h"
#include "grammar.h"
#include "grammarPrint.h"

/* Add quotes to string */
static String c2s (String s)
{
  return Front_StrAllocf ("\"%s\"", remove_quotes(s));
}

/********************/

/* Print the lex preamble */
static void print_preamble (void)
{
  PF ("%%pointer\n");
  PF ("%%{\n");
  PF ("#define fe_parser_input %s_in\n", Rootstr);
  PF ("#include \"%s.h\"\n", Rootstr);
  print_include ("support");
  print_include ("scan_support");
  print_include ("parse_support");
  PF ("#include \"%s_y.h\"\n", Rootstr);
  PF ("#undef YYLMAX\n");
  PF ("#define YYLMAX		(8*1024-1)\n\n");
  PF ("int %s_state_stack_depth=0;\n\n", Rootstr);
  PF ("%%}\n\n");

  PF ("SOL          ^\n");
  PF ("EOL          $\n");
  PF ("Non_digit    [a-zA-Z_]\n");
  PF ("Alphanum     [a-zA-Z_0-9]\n");
  PF ("Digit        [0-9]\n");
  PF ("OctDigit     [0-7]\n");
  PF ("HexDigit     [0-9a-fA-F]\n");
  PF ("Sign         [+-]\n");
  PF ("Quote        [\\']\n");
  PF ("Double_quote [\\\"]\n");
  PF ("Bs           [\\\\]\n");
  PF ("NOT_DQ_BS_CR [\\000-\\014\\016-!#-\\[\\]-\\177]\n");
  PF ("NOT_Q_BS_CR  [\\000-\\014\\016-&(-\\[\\]-\\177]\n");
  PF ("NOT_DQ_BS_LF [\\000-\\011\\013-!#-\\[\\]-\\177]\n");
  PF ("NOT_Q_BS_LF  [\\000-\\011\\013-&(-\\[\\]-\\177]\n");
  PF ("Newline      [\\n]\n");
  PF ("CReturn      [\\r]\n");
  PF ("Feed         [\\012]\n");
  PF ("NoFeed       [\\000-\\011\\013-\\177]\n");
  PF ("FormFeed     [\\f]\n");
  PF ("Space        [\\t ]\n");
  PF ("OctNumber    {OctDigit}{OctDigit}?{OctDigit}?\n");
  PF ("HexNumber    {HexDigit}+\n");
  PF ("Esc          ([abfnrtv\\\"\\'?\\\\\\n]|{OctNumber}|[xX]{HexNumber})\n");
  PF ("ReChar       [\\.\\*\\^\\$\\[\\]\\+\\?\\{\\}]\n");
  PF ("White        [\\t\\f ]\n");
  PF ("Any          [\\000-\\177]\n");
  PF ("HTMLChar     [^<]\n\n");

  PF ("%%%%\n\n");
}

/* record the length of a symbol */
static void record_len (void)
{
  PF ("  record_length (%s_leng);\n", Rootstr);
}

/* record the length and text of a symbol */
static void record_sym (void)
{
  PF ("  record_symbol (%s_leng,%s_text);\n", Rootstr, Rootstr);
}

/* Print the lex postamble, i.e some rules for space and comment */
static void print_postamble (void)
{
  PF ("^[ \\t]*#line.*	{\n");
  record_len ();
  record_sym ();
  PF ("  update_line_and_fname(%s_text);\n", Rootstr);
  PF ("}\n");
  PF ("\n");
  
  PF ("^[ \\t]*#{White}.*	{\n");
  record_len ();
  record_sym ();
  PF ("  update_line_and_fname(%s_text);\n", Rootstr);
  PF ("}\n");
  PF ("\n");
  
  PF ("{CReturn}?{Newline}	{\n");
  record_len ();
  record_sym ();
  PF ("  new_input_line();\n");
  PF ("}\n");
  PF ("\n");
  
  PF ("{White}+	{\n");
  record_len ();
  record_sym ();
  PF ("}\n");
  PF ("\n");
  
  PF (".	{ return NONSENSE; }\n");
  PF ("\n");
  PF ("%%%%\n");
  PF ("\n");

#ifdef IMPORT_ENABLED
  PF ("int %s_wrap()\n", Rootstr);
  PF ("{\n");
  PF ("  if (%s_state_stack_depth==0) return 1;\n", Rootstr);
  PF ("  %s_pop_buffer_state ();\n", Rootstr);
  PF ("  %s_state_stack_depth --;\n", Rootstr);
  PF ("  return 0;\n");
  PF ("}\n\n");
  
  PF ("struct yy_buffer_state *\n");
  PF ("%s_dummy_state (void)\n", Rootstr);
  PF ("{\n");
  PF ("  static struct yy_buffer_state *state = NULL;\n");
  PF ("  if (!state) state = %s__create_buffer (NULL,0);\n");
  PF ("  return state;\n");
  PF ("}\n\n");
  
  PF ("struct yy_buffer_state *\n");
  PF ("%s_scanner_state (void)\n", Rootstr);
  PF ("{\n");
  PF ("  return YY_CURRENT_BUFFER;\n");
  PF ("}\n\n");
#else
  PF ("int %s_wrap()\n", prefix);
  PF ("{ return 1; }\n");
  PF ("\n");
#endif
  
  PF ("void %s_error(char *s)\n", Rootstr);
  PF ("{ if (Front_Parse_Error) Front_Parse_Error (s, %s_text);\n", Rootstr);
  PF ("}\n");
}

/* Get a sub-tree for a hole in case of multi_start */
static void print_get_sub_tree (String s, String t)
{
  if (multi_start == NULL) return;
  PF ("\"%s%s\"\t{\n", multi_start, s);
  if (t) PF ("  %s_lval.%s_type = (%s)Get_sub_tree();\n", Rootstr, s, t);
  PF ("  return %s;\n", s);
  PF ("}\n\n");
}

/* Rule for a hole-token */
static void hole_rule (Ident id)
{ String s = Ident_name(id);

  PF ("\"%s%s\"\t{\n", multi_start, s);
  PF ("  return hole_%s;\n", s);
  PF ("}\n\n");
}

/* Root : { start_id id { Root_multi_action ((void*)$2); } */
static void start_rule (Ident id)
{ String s = Ident_name(id);

  PF ("\"%s_%s\"\t{\n", multi_start, s);
  PF ("  return start_%s;\n", s);
  PF ("}\n\n");
}

/* Generate a hole rule for nonterminal id with fields l */
static void print_hole_rule (Ident id, List_field l)
{
  if (List_field_size(l)!=1) return;
  
  hole_rule (id);
}

/* Generate a start rule for nonterminal id with fields l */
static void print_start_rule (Ident id, List_field l)
{
  if (List_field_size(l)!=1) return;
  
  start_rule (id);
}

/* Generate the rules for start and hole tokens in case of multi_start */
static void print_subgram_sym (ProdRule r)
{
  Ident id = ProdRule_lhs(r);
  List_field fields = ProdRule_fields(r);
  
  if (multi_start==NULL) return;
  
  if (ProdRule_tag(r) == NT_Rule_kind) {
    NonTerminal nt = NT_Rule_nt (r);

    if (NonTerminal_scan(nt) != NULL) return;
    if (!is_macro(nt)) {
      hole_rule (id);
#if 0
      if (NonTerminal_super(nt) != NULL) return;
#endif
      start_rule (id);
      return;
    }
  }
  print_hole_rule (id, fields);
  print_start_rule (id, fields);

}

/* Generate the get_sub_tree rules for terminal symbols */
static void print_subgram_nts (front f)
{
#if 0
  List_NonTerminal l;
  for (l = front_rules(f); l; l = List_NonTerminal_next(l)) {
    NonTerminal nt = List_NonTerminal_data(l);
    String s = Ident_name (NonTerminal_id(nt));
    if (is_macro(nt)) continue;
    if (!NonTerminal_reachable(nt)) continue;
    if (NonTerminal_scan(nt) == NULL) {
      String t = NULL;
      if (ScanInfo_comment(NonTerminal_scan(nt))) continue;
      if (ScanInfo_type(NonTerminal_scan(nt))) 
        t = Ident_name (Type_id(ScanInfo_type(NonTerminal_scan(nt))));
      s = Front_StrAllocf ("%ssym", s);
      print_get_sub_tree (s, t);
    }
  }
#else
  List_Token l;
  for (l = var_tokens; l; l = List_Token_next(l)) {
    Token t = List_Token_data(l);
    if (Token_type(t) == NULL) continue;
    if (Token_type(t) == Create_Ident("Float")) continue;
    if (Token_id(t) == NULL) continue;
    print_get_sub_tree (Ident_name(Token_id(t)), Ident_name(Token_type(t)));
  }
#endif
}

/***************************************************************************/

static List_Ident all_syms = NULL;	/* Names of all tokens */
static List_Token std_syms = NULL;	/* Names of standard tokens used */
List_Token fixed_tokens = NULL;	/* Tokens with a fixed representation */
List_Token var_tokens = NULL;	/* Tokens with a variable representation */

static String str_interp (String s)
{
  Int n = strlen (s);
  String t = fe_malloc (n+1);
  Int i, j = 0;
  
  return s;
  
  for (i=0; i < n; i++) {
    if (s[i] == '\\' &&  s[i+1] == '\\') i++;
    t[j++] = s[i];
  }
  
  t[j] = 0;
  return t;
}

/* Some macro's to create regular expressions */
#define seq_re(a,b)    ((a)==NULL ? (b) : (b)==NULL ? a : Create_SeqRE(no_srcinfo, a, b))
#define choice_re(a,b) ((a)==NULL ? (b) : (b)==NULL ? a : Create_ChoiceRE(no_srcinfo, a, b))
#define par_re(a)      Create_ParRE(no_srcinfo, a)
#define opt_re(a)      Create_OptRE(no_srcinfo, par_re(a))
#define more_re(a)     Create_PlusRE(no_srcinfo, par_re(a))
#define optmore_re(a)  Create_TimesRE(no_srcinfo, par_re(a))
#define string_re(a)   Create_StringRE(no_srcinfo, str_interp(a))
#define ident_re(a)    Create_IdRE(no_srcinfo, a)

static RegExpr alts_re (List_Alternative l);
static RegExpr syms_re (List_Symbol l);
static RegExpr sym_re  (Symbol l);

/* Create the regular expression for a Rhs */
static RegExpr rhs_re (Rhs r)
{
  RegExpr re1 = sym_re(Rhs_syms1(r));
  RegExpr re2 = sym_re(Rhs_syms2(r));
  RegExpr re3 = alts_re (Rhs_alts(r));
  if (re3) re3 = par_re (re3);
  return seq_re (re1, seq_re (re3, re2));
}

/* Create the regular expression for an Alternative */
static RegExpr make_re (Alternative a)
{ 
  RegExpr re = Alternative_re(a);
  if (re != NULL) return COPY_RegExpr(re);
  switch (Alternative_tag(a)) {
    case LabeledAlt_kind:
      re = rhs_re (LabeledAlt_rhs(a));
      break;
    case UnLabeledAlt_kind:
      re = sym_re (UnLabeledAlt_syms(a));
      break;
  }
  Alternative_re(a) = re;
  return re;
}

/* Create the sequence regular expression for a list of Symbols */
static RegExpr syms_re (List_Symbol l)
{ if (l==NULL) return NULL;
  return seq_re (sym_re(List_Symbol_data(l)), syms_re(List_Symbol_next(l)));
}

/* Create the choice regular expression for a list of Alternatives */
static RegExpr alts_re (List_Alternative l)
{ if (l==NULL) return NULL;
  return choice_re (make_re (List_Alternative_data(l)), 
                    alts_re (List_Alternative_next(l)));
}

/* Create the choice regular expression for a list of Symbols */
static RegExpr alts_sym_re (List_Symbol l)
{ if (l==NULL) return NULL;
  return choice_re (sym_re (List_Symbol_data(l)), 
                    alts_sym_re (List_Symbol_next(l)));
}

/* Create representation for a literal symbol */
String term_repr (Symbol s)
{
  switch (Symbol_tag(s)) {
    case StringSymbol_kind:  return StringSymbol_string(s);
    case CharSymbol_kind:    return c2s(CharSymbol_chr(s));
    case KeywordSymbol_kind: return KeywordSymbol_keyword(s);
    default: break;
  }
  return "";
}

/* Create the regular expression for a Symbol */
static RegExpr sym_re (Symbol s)
{
  if (s==NULL) return NULL;
  switch (Symbol_tag(s)) {
    case LabeledSym_kind: return sym_re (LabeledSym_sym(s));
    case CompareSym_kind: return sym_re (Symbol2_sym(s));
    case CharSymbol_kind:
    case KeywordSymbol_kind:
    case StringSymbol_kind: 
      return string_re (term_repr(s));
    case OnceSymbol_kind: return par_re (alts_sym_re (CompoundSym_sym(s)));
    case OptSymbol_kind: return opt_re (alts_sym_re (CompoundSym_sym(s)));
    case OptMoreSymbol_kind: return optmore_re (alts_sym_re (CompoundSym_sym(s)));
    case MoreSymbol_kind: return more_re (alts_sym_re (CompoundSym_sym(s)));
    case SymbolSeq_kind: return syms_re (SymbolSeq_symbols(s));
    case IdSym_kind: 
      { NonTerminal nt = IdSym_nt(s);
        if (nt == NULL) return ident_re (IdSym_id(s));
	return make_re (NonTerminal_alt(nt));
      }
    default:
      break;
  }
  return NULL;
}

/*******************/

/* Names of characters */
static String char_name (Char c)
{
   switch (c) {
     case '_': return "underscore";
     case '!': return "exclaim";
     case '@': return "at";
     case '#': return "hash";
     case '$': return "dollar";
     case '%': return "percent";
     case '^': return "hat";
     case '&': return "ampersand";
     case '*': return "star";
     case '(': return "openpar";
     case ')': return "closepar";
     case '-': return "minus";
     case '=': return "equals";
     case '\\': return "backslash";
     case '~': return "tilda";
     case '`': return "openquote";
     case ':': return "colon";
     case ';': return "semicolon";
     case '\"': return "doublequote";
     case '\'': return "closequote";
     case '<': return "lessthan";
     case ',': return "comma";
     case '>': return "greaterthan";
     case '?': return "questionmark";
     case '/': return "slash";
     case '[': return "openbrk";
     case ']': return "closebrk";
     case '{': return "openchain";
     case '}': return "closechain";
     case '.': return "dot";
     case '|': return "verticalbar";
     case '+': return "plus";
     case ' ': return "space";
  }
  return "";
}

/* Create the name of literal */
static String token_name (String s)
{
  String t;
  String u = "";
  
  s = remove_quotes (s);
  
  for (t = s; t[0]; t++) {
    if (!isalnum((int)t[0]) && t[0] != '_') break;
  }
  if (t[0] == 0) return Front_StrAllocf ("%ssym", s);
  
  for (t = s; t[0]; t++) {
    Char c = t[0];
    if (isalnum((int)c)) u = Front_StrAllocf ("%s%c", u, c);
    else u = Front_StrAllocf ("%s%s", u, char_name(c));
  }
  u = Front_StrAllocf ("%ssym", u);
  return u;
}

static void get_tokens (Alternative alt);

/* Predefined tokens */
static String predef_id (Ident id)
{ if (id == Create_Ident ("Feed"))         return "\\n";
  if (id == Create_Ident ("Newline"))      return "\\n";
  if (id == Create_Ident ("FormFeed"))     return "\\f";
  if (id == Create_Ident ("Space"))        return " ";
  if (id == Create_Ident ("Tab"))          return "\\t";
  if (id == Create_Ident ("Quote"))        return "\\'";
  if (id == Create_Ident ("Double_quote")) return "\\\"";
  if (id == Create_Ident ("Bs"))           return "\\\\";
  return Ident_name(id);
}

/* Find the start of a comment in l */
static RegExpr comment_start (List_Symbol l)
{
  Symbol s;
  RegExpr re;
  
  if (l==NULL) return NULL;
  s = List_Symbol_data(l);
  switch (Symbol_tag(s)) {
    case StringSymbol_kind:
    case CharSymbol_kind:
    case KeywordSymbol_kind:
    case IdSym_kind: 
      re = sym_re (s);
      break;
    default:
      return NULL;
  }
  return seq_re (re, comment_start (List_Symbol_next(l)));
}

/* Find the end of a comment in l */
static String comment_end (List_Symbol l, Bool *done)
{
  Symbol s;
  String next;
  
  if (l==NULL) return "";
  s = List_Symbol_data(l);
  next = comment_end (List_Symbol_next(l), done);
  if (*done) return next;
  
  switch (Symbol_tag(s)) {
    case StringSymbol_kind:
      return Front_StrAllocf ("%s%s", remove_quotes(StringSymbol_string(s)), next);
    case CharSymbol_kind:
      return Front_StrAllocf ("%s%s", remove_quotes(CharSymbol_chr(s)), next);
    case KeywordSymbol_kind:
      return Front_StrAllocf ("%s%s", remove_quotes(KeywordSymbol_keyword(s)), next);
    case IdSym_kind: 
      return Front_StrAllocf ("%s%s", predef_id(IdSym_id(s)), next);
    default:
      *done = TRUE;
      break;
  }
  return next;
}

/* Return a regular expression for the start of a comment */
static RegExpr start_comment (Rhs rhs)
{
  List_Symbol l = SymbolSeq_symbols(Rhs_syms1(rhs));
  return comment_start (l);
}

/* Return the fixed string for the end of a comment */
static String end_comment (Rhs rhs)
{
  List_Symbol l = SymbolSeq_symbols(Rhs_syms1(rhs));
  Bool done = FALSE;
  return comment_end (l, &done);
}

/* Generate the actions for the encoding of a token */
static List_String Make_Actions (Ident id, Ident tid, Bool comment, Rhs rhs)
{
  String  s;
  List_String l = NULL;
  
  if (comment) {
    s = Front_StrAllocf (
       "record_symbol (%s_leng,%s_text);  skip_comment (\"%s\")",
       Rootstr, Rootstr, end_comment (rhs));
    return Create_List_String (s, l);
  }
  
  s = Front_StrAllocf ("record_length (%s_leng); return %s",
    Rootstr, Ident_name(id));
  l = Create_List_String (s, l);
  if (tid != NULL) {
    s = Front_StrAllocf (
      "%s_lval.%s_type = Encode_%s(%s_text)",
      Rootstr, Ident_name(id), Ident_name(tid), Rootstr);
    l = Create_List_String (s, l);
  }
  return l;
}

/* Add token id with type tid and regular expression re, and encoding actions 
   to the list of fixed or variable tokens, either at the beginning or the end, 
   as determined by before.
*/
static void add_token (Ident id, Ident tid, RegExpr re, List_String actions, Bool fixed, Bool before)
{
  Token token = Create_Token (no_srcinfo, re, actions);
  Token_id(token) = id;
  Token_type(token) = tid;
  
  /*printf ("add token %s %d\n", Ident_name(id), fixed);*/
  if (fixed) {
    if (before) {
      fixed_tokens = Create_List_Token(token, fixed_tokens);
    } else {
      FRONT_APPEND_NODE (fixed_tokens, token);
    }
  } else {
    if (before) {
      var_tokens = Create_List_Token(token, var_tokens);
    } else {
      FRONT_APPEND_NODE (var_tokens, token);
    }
  }
}

/* Add a standard token with its type to the list of standard tokens */ 
static void add_std_term (Ident id, Ident tid)
{ 
  Token t;
  id = Create_Ident (append_string (Ident_name(id), "sym"));
  
  if (contains_id (all_syms, id)) return;
  all_syms = Create_List_Ident (id, all_syms);
  t = Create_Token (no_srcinfo, NULL, NULL);
  Token_id(t) = id;
  Token_type(t) = tid;
  std_syms = Create_List_Token (t, std_syms);
}

/* Find a token in the list of standard tokens */
Token is_std_sym (Ident id)
{
  List_Token l;
  for (l = std_syms; l; l = List_Token_next(l)) {
    Token t = List_Token_data(l);
    if (Token_id(t) == id) return t;
  }
  return NULL;
}

/* Add a fixed token for standard symbol s, 
   provided it is in the list of used standard symbols.
*/ 
static void make_std_term (String s)
{
  Ident tid = Create_Ident (s);
  List_String actions;
  RegExpr re;
  Ident id = Create_Ident (append_string (s, "sym"));
  Token t = is_std_sym (id);
  
  if (t == NULL) return;
  
  if (tid == Create_Ident ("Int")) {
    re = Parse_RegExpr ("{Digit}+", 0);
  } else if (tid == Create_Ident ("Oct")) {
    re = Parse_RegExpr ("\"0\"{OctDigit}+", 0);
  } else if (tid == Create_Ident ("Hex")) {
    re = Parse_RegExpr ("(\"0x\"|\"0X\")({Digit}|{HexDigit})+", 0);
  } else if (tid == Create_Ident ("Ident")) {
    re = Parse_RegExpr ("{Non_digit}{Alphanum}*", 0);
  } else if (tid == Create_Ident ("Bool")) {
    re = Parse_RegExpr ("\"FALSE\"|\"TRUE\"", 0);
  } else if (tid == Create_Ident ("Char")) {
    re = Parse_RegExpr ("{Quote}{Any}{Quote}", 0);
  } else if (tid == Create_Ident ("String")) {
    re = Parse_RegExpr ("{Double_quote}({NOT_DQ_BS_LF}|{Bs}{Esc})*{Double_quote}", 0);
  } else if (tid == Create_Ident ("Float")) {
    re = Parse_RegExpr ("{Digit}+\"\\.\"{Digit}*", 0);
  } else {
    FrontFatalError ("Invalid standard symbol found: %s\n", s);
  }
  
  tid = Token_type(t);
  actions = Make_Actions (id, tid, FALSE, NULL);
  
  /*printf ("standard term %s\n", Ident_name(id));*/
  add_token (id, tid, re, actions, FALSE, FALSE);
}

/* Add a fixed token for all standard symbols, 
   provided they are in the list of used standard symbols. 
*/ 
static void make_std_terms (void)
{
  make_std_term ("Bool");
  make_std_term ("Oct");
  make_std_term ("Hex");
  make_std_term ("Int");
  make_std_term ("Float");
  make_std_term ("Char");
  make_std_term ("String");
  make_std_term ("Ident");
}

/* Generate a get_sub_tree rule for a used standard symbol */
static void print_std_term (String s)
{
  Ident id = Create_Ident (append_string (s, "sym"));
  Token t = is_std_sym (id);
  if (t==NULL) return;
  
  print_get_sub_tree (Ident_name(id), Ident_name(Token_type(t)));
}

/* Generate a get_sub_tree rule for all used standard symbols */
static void print_std_terms (void)
{
  print_std_term ("Bool");
  print_std_term ("Oct");
  print_std_term ("Hex");
  print_std_term ("Int");
  print_std_term ("Float");
  print_std_term ("Char");
  print_std_term ("String");
  print_std_term ("Ident");
}

/* Add a fixed token with name id, type t and representation s */
static void add_string_sym (Ident id, String s, Type t)
{
  Ident tid = NULL;
  RegExpr re;
  List_String actions;
  
  if (s==NULL) return;
  if (id==NULL) id = Create_Ident (token_name (s));
  if (contains_id (all_syms, id)) return;
  all_syms = Create_List_Ident (id, all_syms);
  re = string_re(s);
  if (t) tid = Type_id(t);
  actions = Make_Actions (id, tid, FALSE, NULL);
  add_token (id, tid, re, actions, TRUE, FALSE);
}

/* Generate the tokens for non-terminal nt. 
   Also compute the reachability of the nt.
*/ 
static void add_nt_sym (NonTerminal nt)
{
  Ident id;
  Ident tid = NULL;
  ScanInfo scan;
  RegExpr re;
  List_String actions = NULL;
  Bool comment;
  Super super;
  
  if (nt == NULL) return;
  if (NonTerminal_reachable(nt)) return;
  NonTerminal_reachable(nt) = TRUE;

  super = NonTerminal_super(nt);
  if (super != NULL && Super_super(super) != NULL) {
     add_nt_sym (Super_super(super));
  }

  scan = NonTerminal_scan(nt);
  if (scan == NULL) {
    /* Non-terminal, traverse its rhs */
    get_tokens (NonTerminal_alt(nt));
    return;
  }
  
  /* Terminal, add a token */
  id = NonTerminal_id (nt);
  id = Create_Ident (append_string (Ident_name(id), "sym"));
  if (contains_id(all_syms, id)) return;
  all_syms = Create_List_Ident (id, all_syms);
  if (ScanInfo_type(scan)) tid = Type_id(ScanInfo_type(scan));
  comment = ScanInfo_comment(scan);
  if (comment) {
    re = start_comment(NonTerminal_rhs(nt));
  } else {
    re = make_re (NonTerminal_alt(nt));
  }
  actions = Make_Actions (id, tid, comment, NonTerminal_rhs(nt));
  add_token (id, tid, re, actions, FALSE, FALSE);
}

/* Terminal name of a symbol */
String term_name (Symbol s)
{ if (s==NULL) return "";
  switch (Symbol_tag(s)) {
    case StringSymbol_kind: {
      Ident id = StringSymbol_n (s);
      if (id) return Front_StrAllocf("%ssym",Ident_name(id));
      return token_name (StringSymbol_string (s));
    }
    case CharSymbol_kind:
      return token_name (c2s (CharSymbol_chr (s)));
    case KeywordSymbol_kind:
      return token_name (KeywordSymbol_keyword (s));
    default:
      break;
  }
  return "";
}

/* Add the token for a symbol, if it is a terminal.
   In case of the use of non-terminal, travrese the non-terminal recursively.
*/
static void symbol_action (Symbol s)
{ Type type = NULL;
  String string = NULL;
  ImportedNonTerminal imp = NULL;
  NonTerminal nt = NULL;
  Ident id = NULL;
  Ident tid = NULL;
  
  if (s==NULL) return;
  switch (Symbol_tag(s)) {
    case StringSymbol_kind:
      string = StringSymbol_string (s);
      type = StringSymbol_type (s);
      id = StringSymbol_n (s);
      if (id) id = Create_Ident (Front_StrAllocf("%ssym",Ident_name(id)));
      break;
    case CharSymbol_kind:
      string = c2s (CharSymbol_chr (s));
      type = CharSymbol_type (s);
      break;
    case KeywordSymbol_kind:
      string = KeywordSymbol_keyword (s);
      type = KeywordSymbol_type (s);
      break;
    case IdSym_kind:
      imp = IdSym_import(s);
      nt = IdSym_nt(s);
      id = IdSym_id(s);
      string = Ident_name(id);
      tid = id;
      id = Create_Ident (append_string (string, "sym"));
      type = IdSym_type (s);
      if (type != NULL) tid = Type_id(type);
      if (TermType(IdSym_id(s))) {
        add_std_term (IdSym_id(s), tid);
	return;
      }
      if (imp) return;
      if (!nt) {
        add_token (id, tid, NULL, NULL, TRUE, TRUE);
        return;
      }
      break;
    default:
      break;
  }
  if (!nt) add_string_sym (id, string, type);
  add_nt_sym (nt);
}

/* Generate the tokens occurring in alt by traversing it */
static void get_tokens (Alternative alt)
{
  static struct s_void_front_TraverseTable gram_trav;
  
  gram_trav.action_Symbol[PRE_ACTION] = symbol_action;
  
  /*printf("Reachable nonterm %s\n", Ident_name(LabeledAlt_id(alt)));*/
  
  Traverse_void_Alternative (alt, &gram_trav);
}

/* Generate the comment/non-comment tokens in f */
static void add_terms (front f, Bool comment)
{
  List_NonTerminal l;
  
  for (l = front_rules(f); l; l = List_NonTerminal_next(l)) {
    NonTerminal nt = List_NonTerminal_data(l);
    if (NonTerminal_scan(nt) == NULL) continue;
    if (is_macro(nt)) continue;
    if (comment != ScanInfo_comment(NonTerminal_scan(nt))) continue;
    add_nt_sym (nt);
  }
}

/* Generate all (fixed and variable) tokens in f */
void MakeLex (front f)
{
  NonTerminal_reachable(Rootsym) = TRUE;
  
  add_terms (f, TRUE);
  add_terms (f, FALSE);
  get_tokens (NonTerminal_alt (Rootsym));
  make_std_terms ();
}

static void
MyPrint_Token (Token me)
{
  if (!Token_re(me)) return;
  Print_Token (me);
}

/* Generate the lex file */
void GenLex (front f)
{
  NOT_USED(f);
  
  open_print_file (append_string (Rootstr, ".l"), TRUE);
  set_margin(0); set_position(0);
  
  print_preamble();
#if 0
  print_std_terms ();
#endif
  
  for_all_rules (NULL, print_subgram_sym);
  print_subgram_nts (f);

  grammar_print_actions.action_Token [PRE_ACTION] = MyPrint_Token;
  Print_List_Token (fixed_tokens);
  Print_List_Token (var_tokens);
  grammar_print_actions.action_Token [PRE_ACTION] = NULL;
  
  print_postamble();
  close_print_file();
}
