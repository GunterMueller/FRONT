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
#include <string.h>
#include "GenTypes.h"
#include "GenLex.h"
#include "grammarPrint.h"
#include "highlight.h"

static Bool has_type (Type t, String s)
{
  return t != NULL && Type_id(t) == Create_Ident(s);   
}


/********/

static Bool is_brace (RegExpr re)
{ String s;
  if (re == NULL || RegExpr_tag(re) != StringRE_kind) return FALSE;
  
  s = StringRE_s(re);
  if (s[strcspn(s, "{}()[]")] != 0) return TRUE;
  return FALSE;
}

static String get_brace (RegExpr re)
{ Ident id;
  id = Create_Ident (StringRE_s(re));
  if (id == Create_Ident("\"{\"")) return ("{}");
  if (id == Create_Ident("\"(\"")) return ("()");
  if (id == Create_Ident("\"[\"")) return ("[]");
  return NULL;
}

static Bool iskeyword (Token t)
{ RegExpr re = Token_re(t);
  String s;
  Int i;
  
  if (re == NULL || RegExpr_tag(re) != StringRE_kind) return FALSE;
  s = StringRE_s(re);
  i = strspn(&s[1],"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789");
  return s[i+2]==0;
}

static void fixed_token (Token t)
{
  if (is_brace (Token_re(t))) {
    String b = get_brace (Token_re(t));
    if (b) {
      PF ("\t\tbraces:\"%s\"", b);
      PF (":::Keyword::\\n\\\n");
    }
  } else {
    PF ("\t\tkeyword:");
    Print_RegExpr (Token_re(t));
    PF (":::Keyword::\\n\\\n");
  }
}

static void print_kw (Token t)
{ String s = StringRE_s(Token_re(t));
  Int i;
  char u[2] = " ";
  PF ("\t\tkeyword:\"<");
  for (i=1; TRUE; i++) {
    if (s[i+1]==0) break;
    u[0] = s[i];
    Print_String(u);
  }
  PF (">\":::Keyword::\\n\\\n");
}

static void print_str (Token t)
{
  if (Token_type(t) != Create_Ident("String")) return;
  PF ("\t\tstring:");
  Print_RegExpr (Token_re(t));
  PF (":::String::\\n\\\n");
}

static void nedit (front root)
{
  List_Token l;
  
  NOT_USED(root);
  
  open_print_file (Front_StrAllocf("%s.nedit", Rootstr), TRUE);
  PF ("\t%s:1:0{\\n\\\n", Rootstr);
  PF ("\t\tcomment:\"/\\\\*\":\"\\\\*/\"::Comment::\\n\\\n");
  PF ("\t\tcomment:\"\\\\(\\\\*\":\"\\\\*\\\\)\"::Comment::\\n\\\n");
  PF ("\t\tcomment:\"//\":\"\\\\n\"::Comment::\\n\\\n");
  PF ("\t\tcharacter constant:\"'.'\":::Character Const::\\n\\\n");
  PF ("\t\tnumeric constant:\"<((0(x|X)[\\\\da-fA-F]*)|((\\\\d+\\\\.?\\\\d*)|(\\\\.\\\\d+))((e|E)(\\\\+|-)?\\\\d+)?)(L|l|UL|ul|u|U|F|f)?>\":::Numeric Const::\\n\\\n");
  PF ("\t\tbraces:\"[{}]\":::Keyword::\\n\\\n");
  PF ("\t\tstring escape chars:\"\\\\\\\\(.|\\\\n)\":::String1:string:\\n\\\n");
  PF ("\t\tstring:\"\"\"\":\"\"\"\":\"\\\\n\":String::\\n\\\n");
#if 0
  for_all_nonterms (root, printcomment);
  for_all_nonterms (root, print_keywords);
  for_all_nonterms (root, print_characters);
  for_all_nonterms (root, print_nums);
  for_all_nonterms (root, print_braces);
  for_all_nonterms (root, print_escapes);
  for_all_nonterms (root, print_strings);
#endif
  
  for (l = fixed_tokens; l; l = List_Token_next(l)) {
    Token t = List_Token_data(l);
    if (iskeyword(t)) print_kw (t);
  }

#if 0
  for (l = var_tokens; l; l = List_Token_next(l)) {
    Token t = List_Token_data(l);
    print_str (t);
  }
#endif
  
  for (l = fixed_tokens; l; l = List_Token_next(l)) {
    Token t = List_Token_data(l);
    if (iskeyword(t)) continue;
    if (is_brace(Token_re(t))) continue;
    fixed_token (t);
  }
  
  PF ("\t}\\n\\\n");
  close_print_file ();
}

void Highlight (front root)
{
  nedit (root);
}
