#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "front/error.h"
#include "front/support.h"
#include "front/scan_support.h"
#include "front/mem.h"
#include "grammar.h"

#ifndef grammar_SKIP_NODE
# define grammar_SKIP_NODE(n,t) FALSE
#endif

grammar grammar_root;

String grammar_RegExpr_tag_names[] = {
  "ChoiceRE_kind",
  "SeqRE_kind",
  "OptRE_kind",
  "PlusRE_kind",
  "TimesRE_kind",
  "StringRE_kind",
  "SOLRE_kind",
  "EOLRE_kind",
  "IdRE_kind",
  "ParRE_kind",
  "AnyRE_kind",
};

String grammar_ProdRule_tag_names[] = {
  "NT_Rule_kind",
  "Import_Rule_kind",
  "Extra_Rule_kind",
};

grammar_grammar Create_grammar_grammar	(SrcInfo src_info, grammar_Scanner scanner, grammar_Parser parser)
{ grammar_grammar me = (grammar_grammar)fe_malloc(sizeof(*me));
  grammar_grammar_src_info(me) = src_info;
  grammar_grammar_scanner(me) = scanner;
  grammar_grammar_parser(me) = parser;
  return me;
}

grammar_Scanner Create_grammar_Scanner	(SrcInfo src_info, List_grammar_Token tokens)
{ grammar_Scanner me = (grammar_Scanner)fe_malloc(sizeof(*me));
  grammar_Scanner_src_info(me) = src_info;
  grammar_Scanner_tokens(me) = tokens;
  return me;
}

grammar_Token Create_grammar_Token	(SrcInfo src_info, grammar_RegExpr re, List_String actions)
{ grammar_Token me = (grammar_Token)fe_malloc(sizeof(*me));
  grammar_Token_src_info(me) = src_info;
  grammar_Token_re(me) = re;
  grammar_Token_actions(me) = actions;
  grammar_Token_id(me) = NULL;
  grammar_Token_type(me) = NULL;
  return me;
}

grammar_AnyRE Create_grammar_AnyRE	(SrcInfo src_info)
{ grammar_AnyRE me = (grammar_AnyRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_RegExpr_tag(me) = grammar_AnyRE_kind;
  return me;
}

grammar_ParRE Create_grammar_ParRE	(SrcInfo src_info, grammar_RegExpr re)
{ grammar_ParRE me = (grammar_ParRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_ParRE_re(me) = re;
  grammar_RegExpr_tag(me) = grammar_ParRE_kind;
  return me;
}

grammar_IdRE Create_grammar_IdRE	(SrcInfo src_info, Ident id)
{ grammar_IdRE me = (grammar_IdRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_IdRE_id(me) = id;
  grammar_RegExpr_tag(me) = grammar_IdRE_kind;
  return me;
}

grammar_EOLRE Create_grammar_EOLRE	(SrcInfo src_info)
{ grammar_EOLRE me = (grammar_EOLRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_RegExpr_tag(me) = grammar_EOLRE_kind;
  return me;
}

grammar_SOLRE Create_grammar_SOLRE	(SrcInfo src_info)
{ grammar_SOLRE me = (grammar_SOLRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_RegExpr_tag(me) = grammar_SOLRE_kind;
  return me;
}

grammar_StringRE Create_grammar_StringRE	(SrcInfo src_info, String s)
{ grammar_StringRE me = (grammar_StringRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_StringRE_s(me) = s;
  grammar_RegExpr_tag(me) = grammar_StringRE_kind;
  return me;
}

grammar_TimesRE Create_grammar_TimesRE	(SrcInfo src_info, grammar_RegExpr re)
{ grammar_TimesRE me = (grammar_TimesRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_PostRE_re(me) = re;
  grammar_RegExpr_tag(me) = grammar_TimesRE_kind;
  return me;
}

grammar_PlusRE Create_grammar_PlusRE	(SrcInfo src_info, grammar_RegExpr re)
{ grammar_PlusRE me = (grammar_PlusRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_PostRE_re(me) = re;
  grammar_RegExpr_tag(me) = grammar_PlusRE_kind;
  return me;
}

grammar_OptRE Create_grammar_OptRE	(SrcInfo src_info, grammar_RegExpr re)
{ grammar_OptRE me = (grammar_OptRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_PostRE_re(me) = re;
  grammar_RegExpr_tag(me) = grammar_OptRE_kind;
  return me;
}

grammar_SeqRE Create_grammar_SeqRE	(SrcInfo src_info, grammar_RegExpr head, grammar_RegExpr tail)
{ grammar_SeqRE me = (grammar_SeqRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_SeqRE_head(me) = head;
  grammar_SeqRE_tail(me) = tail;
  grammar_RegExpr_tag(me) = grammar_SeqRE_kind;
  return me;
}

grammar_ChoiceRE Create_grammar_ChoiceRE	(SrcInfo src_info, grammar_RegExpr head, grammar_RegExpr tail)
{ grammar_ChoiceRE me = (grammar_ChoiceRE)fe_malloc(sizeof(*me));
  grammar_RegExpr_src_info(me) = src_info;
  grammar_ChoiceRE_head(me) = head;
  grammar_ChoiceRE_tail(me) = tail;
  grammar_RegExpr_tag(me) = grammar_ChoiceRE_kind;
  return me;
}

grammar_Parser Create_grammar_Parser	(SrcInfo src_info, List_grammar_ProdRule rules)
{ grammar_Parser me = (grammar_Parser)fe_malloc(sizeof(*me));
  grammar_Parser_src_info(me) = src_info;
  grammar_Parser_rules(me) = rules;
  return me;
}

grammar_Extra_Rule Create_grammar_Extra_Rule	(SrcInfo src_info, Ident lhs)
{ grammar_Extra_Rule me = (grammar_Extra_Rule)fe_malloc(sizeof(*me));
  grammar_ProdRule_src_info(me) = src_info;
  grammar_ProdRule_lhs(me) = lhs;
  grammar_ProdRule_tag(me) = grammar_Extra_Rule_kind;
  grammar_ProdRule_fields(me) = NULL;
  grammar_Extra_Rule_sym(me) = NULL;
  return me;
}

grammar_Import_Rule Create_grammar_Import_Rule	(SrcInfo src_info, Ident lhs)
{ grammar_Import_Rule me = (grammar_Import_Rule)fe_malloc(sizeof(*me));
  grammar_ProdRule_src_info(me) = src_info;
  grammar_ProdRule_lhs(me) = lhs;
  grammar_ProdRule_tag(me) = grammar_Import_Rule_kind;
  grammar_ProdRule_fields(me) = NULL;
  grammar_Import_Rule_type(me) = NULL;
  grammar_Import_Rule_grammar(me) = NULL;
  grammar_Import_Rule_imp(me) = NULL;
  return me;
}

grammar_NT_Rule Create_grammar_NT_Rule	(SrcInfo src_info, Ident lhs)
{ grammar_NT_Rule me = (grammar_NT_Rule)fe_malloc(sizeof(*me));
  grammar_ProdRule_src_info(me) = src_info;
  grammar_ProdRule_lhs(me) = lhs;
  grammar_ProdRule_tag(me) = grammar_NT_Rule_kind;
  grammar_ProdRule_fields(me) = NULL;
  grammar_NT_Rule_nt(me) = NULL;
  grammar_NT_Rule_alt(me) = NULL;
  grammar_NT_Rule_rhs(me) = NULL;
  grammar_NT_Rule_fields(me) = NULL;
  return me;
}

grammar_Scope Create_grammar_Scope	(grammar_Scope next)
{ grammar_Scope me = (grammar_Scope)fe_malloc(sizeof(*me));
  grammar_Scope_next(me) = next;
  grammar_Scope__self(me) = 0;
  grammar_Scope__end(me) = 0;
  return me;
}

Pointer Traverse_grammar_grammar (grammar_grammar me, TraverseTable action, Pointer val)
{ 
  if (grammar_SKIP_NODE(grammar, me)) return val;
  if (action->action_grammar[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_grammar[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_grammar)
  { 
  if (!action->skip_children_grammar) {
    if (action->traversal != Traverse_Down)  val = Traverse_grammar_Scanner (grammar_grammar_scanner(me), action, val);
    else Traverse_grammar_Scanner (grammar_grammar_scanner(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_grammar_Parser (grammar_grammar_parser(me), action, val);
    else Traverse_grammar_Parser (grammar_grammar_parser(me), action, val);
  }
  }
  if (action->action_grammar[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_grammar[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_grammar_Scanner (grammar_Scanner me, TraverseTable action, Pointer val)
{ 
  if (grammar_SKIP_NODE(Scanner, me)) return val;
  if (action->action_Scanner[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scanner[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Scanner)
  { 
  if (!action->skip_children_Scanner) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_grammar_Token (grammar_Scanner_tokens(me), action, val);
    else Traverse_List_grammar_Token (grammar_Scanner_tokens(me), action, val);
  }
  }
  if (action->action_Scanner[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scanner[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_grammar_Token (grammar_Token me, TraverseTable action, Pointer val)
{ 
  if (grammar_SKIP_NODE(Token, me)) return val;
  if (action->action_Token[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Token[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Token)
  { 
  if (!action->skip_children_Token) {
    if (action->traversal != Traverse_Down)  val = Traverse_grammar_RegExpr (grammar_Token_re(me), action, val);
    else Traverse_grammar_RegExpr (grammar_Token_re(me), action, val);
  }
  }
  if (action->action_Token[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Token[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_grammar_RegExpr (grammar_RegExpr me, TraverseTable action, Pointer val)
{ 
  if (grammar_SKIP_NODE(RegExpr, me)) return val;
  if (action->action_RegExpr[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_RegExpr[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_RegExpr)
  { switch (grammar_RegExpr_tag(me)) {
      case grammar_ChoiceRE_kind:
        if (action->action_ChoiceRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ChoiceRE[PRE_ACTION](me, val);
        }
        if (!action->skip_children_ChoiceRE) {
          if (action->traversal != Traverse_Down)  val = Traverse_grammar_RegExpr (grammar_ChoiceRE_head(me), action, val);
          else Traverse_grammar_RegExpr (grammar_ChoiceRE_head(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_grammar_RegExpr (grammar_ChoiceRE_tail(me), action, val);
          else Traverse_grammar_RegExpr (grammar_ChoiceRE_tail(me), action, val);
        }
        if (action->action_ChoiceRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ChoiceRE[POST_ACTION](me, val);
        }
        break;
      case grammar_SeqRE_kind:
        if (action->action_SeqRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SeqRE[PRE_ACTION](me, val);
        }
        if (!action->skip_children_SeqRE) {
          if (action->traversal != Traverse_Down)  val = Traverse_grammar_RegExpr (grammar_SeqRE_head(me), action, val);
          else Traverse_grammar_RegExpr (grammar_SeqRE_head(me), action, val);
          if (action->traversal != Traverse_Down)  val = Traverse_grammar_RegExpr (grammar_SeqRE_tail(me), action, val);
          else Traverse_grammar_RegExpr (grammar_SeqRE_tail(me), action, val);
        }
        if (action->action_SeqRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SeqRE[POST_ACTION](me, val);
        }
        break;
      case grammar_OptRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PostRE[PRE_ACTION](me, val);
        }
        if (action->action_OptRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OptRE[PRE_ACTION](me, val);
        }
        if (!action->skip_children_PostRE) {
          if (action->traversal != Traverse_Down)  val = Traverse_grammar_RegExpr (grammar_PostRE_re(me), action, val);
          else Traverse_grammar_RegExpr (grammar_PostRE_re(me), action, val);
        }
        if (action->action_OptRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_OptRE[POST_ACTION](me, val);
        }
        if (action->action_PostRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PostRE[POST_ACTION](me, val);
        }
        break;
      case grammar_PlusRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PostRE[PRE_ACTION](me, val);
        }
        if (action->action_PlusRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PlusRE[PRE_ACTION](me, val);
        }
        if (!action->skip_children_PostRE) {
          if (action->traversal != Traverse_Down)  val = Traverse_grammar_RegExpr (grammar_PostRE_re(me), action, val);
          else Traverse_grammar_RegExpr (grammar_PostRE_re(me), action, val);
        }
        if (action->action_PlusRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PlusRE[POST_ACTION](me, val);
        }
        if (action->action_PostRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PostRE[POST_ACTION](me, val);
        }
        break;
      case grammar_TimesRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PostRE[PRE_ACTION](me, val);
        }
        if (action->action_TimesRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_TimesRE[PRE_ACTION](me, val);
        }
        if (!action->skip_children_PostRE) {
          if (action->traversal != Traverse_Down)  val = Traverse_grammar_RegExpr (grammar_PostRE_re(me), action, val);
          else Traverse_grammar_RegExpr (grammar_PostRE_re(me), action, val);
        }
        if (action->action_TimesRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_TimesRE[POST_ACTION](me, val);
        }
        if (action->action_PostRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_PostRE[POST_ACTION](me, val);
        }
        break;
      case grammar_StringRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[PRE_ACTION](me, val);
        }
        if (action->action_StringRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringRE[PRE_ACTION](me, val);
        }
        if (action->action_StringRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_StringRE[POST_ACTION](me, val);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[POST_ACTION](me, val);
        }
        break;
      case grammar_SOLRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[PRE_ACTION](me, val);
        }
        if (action->action_SOLRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SOLRE[PRE_ACTION](me, val);
        }
        if (action->action_SOLRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_SOLRE[POST_ACTION](me, val);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[POST_ACTION](me, val);
        }
        break;
      case grammar_EOLRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[PRE_ACTION](me, val);
        }
        if (action->action_EOLRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_EOLRE[PRE_ACTION](me, val);
        }
        if (action->action_EOLRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_EOLRE[POST_ACTION](me, val);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[POST_ACTION](me, val);
        }
        break;
      case grammar_IdRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[PRE_ACTION](me, val);
        }
        if (action->action_IdRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdRE[PRE_ACTION](me, val);
        }
        if (action->action_IdRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_IdRE[POST_ACTION](me, val);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[POST_ACTION](me, val);
        }
        break;
      case grammar_ParRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[PRE_ACTION](me, val);
        }
        if (action->action_ParRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ParRE[PRE_ACTION](me, val);
        }
        if (!action->skip_children_ParRE) {
          if (action->traversal != Traverse_Down)  val = Traverse_grammar_RegExpr (grammar_ParRE_re(me), action, val);
          else Traverse_grammar_RegExpr (grammar_ParRE_re(me), action, val);
        }
        if (action->action_ParRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_ParRE[POST_ACTION](me, val);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[POST_ACTION](me, val);
        }
        break;
      case grammar_AnyRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[PRE_ACTION](me, val);
        }
        if (action->action_AnyRE[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AnyRE[PRE_ACTION](me, val);
        }
        if (action->action_AnyRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_AnyRE[POST_ACTION](me, val);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_BasicRE[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_RegExpr[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_RegExpr[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_grammar_Parser (grammar_Parser me, TraverseTable action, Pointer val)
{ 
  if (grammar_SKIP_NODE(Parser, me)) return val;
  if (action->action_Parser[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Parser[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Parser)
  { 
  if (!action->skip_children_Parser) {
    if (action->traversal != Traverse_Down)  val = Traverse_List_grammar_ProdRule (grammar_Parser_rules(me), action, val);
    else Traverse_List_grammar_ProdRule (grammar_Parser_rules(me), action, val);
  }
  }
  if (action->action_Parser[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Parser[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_grammar_ProdRule (grammar_ProdRule me, TraverseTable action, Pointer val)
{ 
  if (grammar_SKIP_NODE(ProdRule, me)) return val;
  if (action->action_ProdRule[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ProdRule[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_ProdRule)
  { switch (grammar_ProdRule_tag(me)) {
      case grammar_NT_Rule_kind:
        if (action->action_NT_Rule[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NT_Rule[PRE_ACTION](me, val);
        }
        if (action->action_NT_Rule[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_NT_Rule[POST_ACTION](me, val);
        }
        break;
      case grammar_Import_Rule_kind:
        if (action->action_Import_Rule[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Import_Rule[PRE_ACTION](me, val);
        }
        if (action->action_Import_Rule[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Import_Rule[POST_ACTION](me, val);
        }
        break;
      case grammar_Extra_Rule_kind:
        if (action->action_Extra_Rule[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Extra_Rule[PRE_ACTION](me, val);
        }
        if (action->action_Extra_Rule[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
          val = action->action_Extra_Rule[POST_ACTION](me, val);
        }
        break;
    }
  }
  if (action->action_ProdRule[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_ProdRule[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_grammar_Scope (grammar_Scope me, TraverseTable action, Pointer val)
{ 
  if (grammar_SKIP_NODE(Scope, me)) return val;
  if (action->action_Scope[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_Scope)
  { 
  if (!action->skip_children_Scope) {
    if (action->traversal != Traverse_Down)  val = Traverse_grammar_Scope (grammar_Scope_next(me), action, val);
    else Traverse_grammar_Scope (grammar_Scope_next(me), action, val);
  }
  }
  if (action->action_Scope[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_Scope[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_grammar_ProdRule (List_grammar_ProdRule me, TraverseTable action, Pointer val)
{ 
  if (grammar_SKIP_NODE(List_ProdRule, me)) return val;
  if (action->action_List_ProdRule[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_ProdRule[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_ProdRule)
  { 
  if (!action->skip_children_List_ProdRule) {
    if (action->traversal != Traverse_Down)  val = Traverse_grammar_ProdRule (List_grammar_ProdRule_data(me), action, val);
    else Traverse_grammar_ProdRule (List_grammar_ProdRule_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_grammar_ProdRule (List_grammar_ProdRule_next(me), action, val);
    else Traverse_List_grammar_ProdRule (List_grammar_ProdRule_next(me), action, val);
  }
  }
  if (action->action_List_ProdRule[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_ProdRule[POST_ACTION](me, val);
  }
  return val;
}

Pointer Traverse_List_grammar_Token (List_grammar_Token me, TraverseTable action, Pointer val)
{ 
  if (grammar_SKIP_NODE(List_Token, me)) return val;
  if (action->action_List_Token[PRE_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Token[PRE_ACTION](me, val);
  }
  if (me != NULL && !action->skip_children_List_Token)
  { 
  if (!action->skip_children_List_Token) {
    if (action->traversal != Traverse_Down)  val = Traverse_grammar_Token (List_grammar_Token_data(me), action, val);
    else Traverse_grammar_Token (List_grammar_Token_data(me), action, val);
    if (action->traversal != Traverse_Down)  val = Traverse_List_grammar_Token (List_grammar_Token_next(me), action, val);
    else Traverse_List_grammar_Token (List_grammar_Token_next(me), action, val);
  }
  }
  if (action->action_List_Token[POST_ACTION] != NULL && !(action->traversal == Traverse_Stop && val==NULL)) {
    val = action->action_List_Token[POST_ACTION](me, val);
  }
  return val;
}

void Traverse_void_grammar_grammar (grammar_grammar me, void_grammar_TraverseTable action)
{ 
  if (grammar_SKIP_NODE(grammar, me)) return;
  if (action->action_grammar[PRE_ACTION] != NULL) {
    action->action_grammar[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_grammar)
  { 
  if (!action->skip_children_grammar) {
    Traverse_void_grammar_Scanner (grammar_grammar_scanner(me), action);
    Traverse_void_grammar_Parser (grammar_grammar_parser(me), action);
  }
  }
  if (action->action_grammar[POST_ACTION] != NULL) {
    action->action_grammar[POST_ACTION](me);
  }
}

void Traverse_void_grammar_Scanner (grammar_Scanner me, void_grammar_TraverseTable action)
{ 
  if (grammar_SKIP_NODE(Scanner, me)) return;
  if (action->action_Scanner[PRE_ACTION] != NULL) {
    action->action_Scanner[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Scanner)
  { 
  if (!action->skip_children_Scanner) {
    Traverse_void_List_grammar_Token (grammar_Scanner_tokens(me), action);
  }
  }
  if (action->action_Scanner[POST_ACTION] != NULL) {
    action->action_Scanner[POST_ACTION](me);
  }
}

void Traverse_void_grammar_Token (grammar_Token me, void_grammar_TraverseTable action)
{ 
  if (grammar_SKIP_NODE(Token, me)) return;
  if (action->action_Token[PRE_ACTION] != NULL) {
    action->action_Token[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Token)
  { 
  if (!action->skip_children_Token) {
    Traverse_void_grammar_RegExpr (grammar_Token_re(me), action);
  }
  }
  if (action->action_Token[POST_ACTION] != NULL) {
    action->action_Token[POST_ACTION](me);
  }
}

void Traverse_void_grammar_RegExpr (grammar_RegExpr me, void_grammar_TraverseTable action)
{ 
  if (grammar_SKIP_NODE(RegExpr, me)) return;
  if (action->action_RegExpr[PRE_ACTION] != NULL) {
    action->action_RegExpr[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_RegExpr)
  { switch (grammar_RegExpr_tag(me)) {
      case grammar_ChoiceRE_kind:
        if (action->action_ChoiceRE[PRE_ACTION] != NULL) {
          action->action_ChoiceRE[PRE_ACTION](me);
        }
        if (!action->skip_children_ChoiceRE) {
          Traverse_void_grammar_RegExpr (grammar_ChoiceRE_head(me), action);
          Traverse_void_grammar_RegExpr (grammar_ChoiceRE_tail(me), action);
        }
        if (action->action_ChoiceRE[POST_ACTION] != NULL) {
          action->action_ChoiceRE[POST_ACTION](me);
        }
        break;
      case grammar_SeqRE_kind:
        if (action->action_SeqRE[PRE_ACTION] != NULL) {
          action->action_SeqRE[PRE_ACTION](me);
        }
        if (!action->skip_children_SeqRE) {
          Traverse_void_grammar_RegExpr (grammar_SeqRE_head(me), action);
          Traverse_void_grammar_RegExpr (grammar_SeqRE_tail(me), action);
        }
        if (action->action_SeqRE[POST_ACTION] != NULL) {
          action->action_SeqRE[POST_ACTION](me);
        }
        break;
      case grammar_OptRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL) {
          action->action_PostRE[PRE_ACTION](me);
        }
        if (action->action_OptRE[PRE_ACTION] != NULL) {
          action->action_OptRE[PRE_ACTION](me);
        }
        if (!action->skip_children_PostRE) {
          Traverse_void_grammar_RegExpr (grammar_PostRE_re(me), action);
        }
        if (action->action_OptRE[POST_ACTION] != NULL) {
          action->action_OptRE[POST_ACTION](me);
        }
        if (action->action_PostRE[POST_ACTION] != NULL) {
          action->action_PostRE[POST_ACTION](me);
        }
        break;
      case grammar_PlusRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL) {
          action->action_PostRE[PRE_ACTION](me);
        }
        if (action->action_PlusRE[PRE_ACTION] != NULL) {
          action->action_PlusRE[PRE_ACTION](me);
        }
        if (!action->skip_children_PostRE) {
          Traverse_void_grammar_RegExpr (grammar_PostRE_re(me), action);
        }
        if (action->action_PlusRE[POST_ACTION] != NULL) {
          action->action_PlusRE[POST_ACTION](me);
        }
        if (action->action_PostRE[POST_ACTION] != NULL) {
          action->action_PostRE[POST_ACTION](me);
        }
        break;
      case grammar_TimesRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL) {
          action->action_PostRE[PRE_ACTION](me);
        }
        if (action->action_TimesRE[PRE_ACTION] != NULL) {
          action->action_TimesRE[PRE_ACTION](me);
        }
        if (!action->skip_children_PostRE) {
          Traverse_void_grammar_RegExpr (grammar_PostRE_re(me), action);
        }
        if (action->action_TimesRE[POST_ACTION] != NULL) {
          action->action_TimesRE[POST_ACTION](me);
        }
        if (action->action_PostRE[POST_ACTION] != NULL) {
          action->action_PostRE[POST_ACTION](me);
        }
        break;
      case grammar_StringRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          action->action_BasicRE[PRE_ACTION](me);
        }
        if (action->action_StringRE[PRE_ACTION] != NULL) {
          action->action_StringRE[PRE_ACTION](me);
        }
        if (action->action_StringRE[POST_ACTION] != NULL) {
          action->action_StringRE[POST_ACTION](me);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          action->action_BasicRE[POST_ACTION](me);
        }
        break;
      case grammar_SOLRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          action->action_BasicRE[PRE_ACTION](me);
        }
        if (action->action_SOLRE[PRE_ACTION] != NULL) {
          action->action_SOLRE[PRE_ACTION](me);
        }
        if (action->action_SOLRE[POST_ACTION] != NULL) {
          action->action_SOLRE[POST_ACTION](me);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          action->action_BasicRE[POST_ACTION](me);
        }
        break;
      case grammar_EOLRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          action->action_BasicRE[PRE_ACTION](me);
        }
        if (action->action_EOLRE[PRE_ACTION] != NULL) {
          action->action_EOLRE[PRE_ACTION](me);
        }
        if (action->action_EOLRE[POST_ACTION] != NULL) {
          action->action_EOLRE[POST_ACTION](me);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          action->action_BasicRE[POST_ACTION](me);
        }
        break;
      case grammar_IdRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          action->action_BasicRE[PRE_ACTION](me);
        }
        if (action->action_IdRE[PRE_ACTION] != NULL) {
          action->action_IdRE[PRE_ACTION](me);
        }
        if (action->action_IdRE[POST_ACTION] != NULL) {
          action->action_IdRE[POST_ACTION](me);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          action->action_BasicRE[POST_ACTION](me);
        }
        break;
      case grammar_ParRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          action->action_BasicRE[PRE_ACTION](me);
        }
        if (action->action_ParRE[PRE_ACTION] != NULL) {
          action->action_ParRE[PRE_ACTION](me);
        }
        if (!action->skip_children_ParRE) {
          Traverse_void_grammar_RegExpr (grammar_ParRE_re(me), action);
        }
        if (action->action_ParRE[POST_ACTION] != NULL) {
          action->action_ParRE[POST_ACTION](me);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          action->action_BasicRE[POST_ACTION](me);
        }
        break;
      case grammar_AnyRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          action->action_BasicRE[PRE_ACTION](me);
        }
        if (action->action_AnyRE[PRE_ACTION] != NULL) {
          action->action_AnyRE[PRE_ACTION](me);
        }
        if (action->action_AnyRE[POST_ACTION] != NULL) {
          action->action_AnyRE[POST_ACTION](me);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          action->action_BasicRE[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_RegExpr[POST_ACTION] != NULL) {
    action->action_RegExpr[POST_ACTION](me);
  }
}

void Traverse_void_grammar_Parser (grammar_Parser me, void_grammar_TraverseTable action)
{ 
  if (grammar_SKIP_NODE(Parser, me)) return;
  if (action->action_Parser[PRE_ACTION] != NULL) {
    action->action_Parser[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Parser)
  { 
  if (!action->skip_children_Parser) {
    Traverse_void_List_grammar_ProdRule (grammar_Parser_rules(me), action);
  }
  }
  if (action->action_Parser[POST_ACTION] != NULL) {
    action->action_Parser[POST_ACTION](me);
  }
}

void Traverse_void_grammar_ProdRule (grammar_ProdRule me, void_grammar_TraverseTable action)
{ 
  if (grammar_SKIP_NODE(ProdRule, me)) return;
  if (action->action_ProdRule[PRE_ACTION] != NULL) {
    action->action_ProdRule[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_ProdRule)
  { switch (grammar_ProdRule_tag(me)) {
      case grammar_NT_Rule_kind:
        if (action->action_NT_Rule[PRE_ACTION] != NULL) {
          action->action_NT_Rule[PRE_ACTION](me);
        }
        if (action->action_NT_Rule[POST_ACTION] != NULL) {
          action->action_NT_Rule[POST_ACTION](me);
        }
        break;
      case grammar_Import_Rule_kind:
        if (action->action_Import_Rule[PRE_ACTION] != NULL) {
          action->action_Import_Rule[PRE_ACTION](me);
        }
        if (action->action_Import_Rule[POST_ACTION] != NULL) {
          action->action_Import_Rule[POST_ACTION](me);
        }
        break;
      case grammar_Extra_Rule_kind:
        if (action->action_Extra_Rule[PRE_ACTION] != NULL) {
          action->action_Extra_Rule[PRE_ACTION](me);
        }
        if (action->action_Extra_Rule[POST_ACTION] != NULL) {
          action->action_Extra_Rule[POST_ACTION](me);
        }
        break;
    }
  }
  if (action->action_ProdRule[POST_ACTION] != NULL) {
    action->action_ProdRule[POST_ACTION](me);
  }
}

void Traverse_void_grammar_Scope (grammar_Scope me, void_grammar_TraverseTable action)
{ 
  if (grammar_SKIP_NODE(Scope, me)) return;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    action->action_Scope[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_Scope)
  { 
  if (!action->skip_children_Scope) {
    Traverse_void_grammar_Scope (grammar_Scope_next(me), action);
  }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    action->action_Scope[POST_ACTION](me);
  }
}

void Traverse_void_List_grammar_ProdRule (List_grammar_ProdRule me, void_grammar_TraverseTable action)
{ 
  if (grammar_SKIP_NODE(List_ProdRule, me)) return;
  if (action->action_List_ProdRule[PRE_ACTION] != NULL) {
    action->action_List_ProdRule[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_ProdRule)
  { 
  if (!action->skip_children_List_ProdRule) {
    Traverse_void_grammar_ProdRule (List_grammar_ProdRule_data(me), action);
    Traverse_void_List_grammar_ProdRule (List_grammar_ProdRule_next(me), action);
  }
  }
  if (action->action_List_ProdRule[POST_ACTION] != NULL) {
    action->action_List_ProdRule[POST_ACTION](me);
  }
}

void Traverse_void_List_grammar_Token (List_grammar_Token me, void_grammar_TraverseTable action)
{ 
  if (grammar_SKIP_NODE(List_Token, me)) return;
  if (action->action_List_Token[PRE_ACTION] != NULL) {
    action->action_List_Token[PRE_ACTION](me);
  }
  if (me != NULL && !action->skip_children_List_Token)
  { 
  if (!action->skip_children_List_Token) {
    Traverse_void_grammar_Token (List_grammar_Token_data(me), action);
    Traverse_void_List_grammar_Token (List_grammar_Token_next(me), action);
  }
  }
  if (action->action_List_Token[POST_ACTION] != NULL) {
    action->action_List_Token[POST_ACTION](me);
  }
}

grammar_grammar Traverse_copy_grammar_grammar (grammar_grammar me, copy_grammar_TraverseTable action)
{ grammar_grammar _new = me, _old = me;
  if (action->action_grammar[PRE_ACTION] != NULL) {
    _new = action->action_grammar[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (grammar_grammar)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_grammar) {
    grammar_grammar_scanner(me) = Traverse_copy_grammar_Scanner (grammar_grammar_scanner(me), action);
    grammar_grammar_parser(me) = Traverse_copy_grammar_Parser (grammar_grammar_parser(me), action);
  }
  }
  if (action->action_grammar[POST_ACTION] != NULL) {
    me = action->action_grammar[POST_ACTION](me, _old);
  }
  return me;
}

grammar_Scanner Traverse_copy_grammar_Scanner (grammar_Scanner me, copy_grammar_TraverseTable action)
{ grammar_Scanner _new = me, _old = me;
  if (action->action_Scanner[PRE_ACTION] != NULL) {
    _new = action->action_Scanner[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (grammar_Scanner)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Scanner) {
    grammar_Scanner_tokens(me) = Traverse_copy_List_grammar_Token (grammar_Scanner_tokens(me), action);
  }
  }
  if (action->action_Scanner[POST_ACTION] != NULL) {
    me = action->action_Scanner[POST_ACTION](me, _old);
  }
  return me;
}

grammar_Token Traverse_copy_grammar_Token (grammar_Token me, copy_grammar_TraverseTable action)
{ grammar_Token _new = me, _old = me;
  if (action->action_Token[PRE_ACTION] != NULL) {
    _new = action->action_Token[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (grammar_Token)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Token) {
    grammar_Token_re(me) = Traverse_copy_grammar_RegExpr (grammar_Token_re(me), action);
    grammar_Token_actions(me) = Traverse_copy_List_String (grammar_Token_actions(me), action);
  }
    if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
      grammar_Token_id(me) = NULL;
      grammar_Token_type(me) = NULL;
    }
  }
  if (action->action_Token[POST_ACTION] != NULL) {
    me = action->action_Token[POST_ACTION](me, _old);
  }
  return me;
}

grammar_RegExpr Traverse_copy_grammar_RegExpr (grammar_RegExpr me, copy_grammar_TraverseTable action)
{ grammar_RegExpr _new = me, _old = me;
  if (action->action_RegExpr[PRE_ACTION] != NULL) {
    _new = action->action_RegExpr[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (grammar_RegExpr)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (grammar_RegExpr_tag(me)) {
      case grammar_ChoiceRE_kind:
        if (action->action_ChoiceRE[PRE_ACTION] != NULL) {
          _new = action->action_ChoiceRE[PRE_ACTION](me, me);
        }
        if (!action->skip_children_ChoiceRE) {
          grammar_ChoiceRE_head(me) = Traverse_copy_grammar_RegExpr (grammar_ChoiceRE_head(me), action);
          grammar_ChoiceRE_tail(me) = Traverse_copy_grammar_RegExpr (grammar_ChoiceRE_tail(me), action);
        }
        if (action->action_ChoiceRE[POST_ACTION] != NULL) {
          _new = action->action_ChoiceRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_SeqRE_kind:
        if (action->action_SeqRE[PRE_ACTION] != NULL) {
          _new = action->action_SeqRE[PRE_ACTION](me, me);
        }
        if (!action->skip_children_SeqRE) {
          grammar_SeqRE_head(me) = Traverse_copy_grammar_RegExpr (grammar_SeqRE_head(me), action);
          grammar_SeqRE_tail(me) = Traverse_copy_grammar_RegExpr (grammar_SeqRE_tail(me), action);
        }
        if (action->action_SeqRE[POST_ACTION] != NULL) {
          _new = action->action_SeqRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_OptRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL) {
          _new = action->action_PostRE[PRE_ACTION](me, me);
        }
        if (action->action_OptRE[PRE_ACTION] != NULL) {
          _new = action->action_OptRE[PRE_ACTION](me, me);
        }
        if (!action->skip_children_PostRE) {
          grammar_PostRE_re(me) = Traverse_copy_grammar_RegExpr (grammar_PostRE_re(me), action);
        }
        if (action->action_OptRE[POST_ACTION] != NULL) {
          _new = action->action_OptRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_PostRE[POST_ACTION] != NULL) {
          _new = action->action_PostRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_PlusRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL) {
          _new = action->action_PostRE[PRE_ACTION](me, me);
        }
        if (action->action_PlusRE[PRE_ACTION] != NULL) {
          _new = action->action_PlusRE[PRE_ACTION](me, me);
        }
        if (!action->skip_children_PostRE) {
          grammar_PostRE_re(me) = Traverse_copy_grammar_RegExpr (grammar_PostRE_re(me), action);
        }
        if (action->action_PlusRE[POST_ACTION] != NULL) {
          _new = action->action_PlusRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_PostRE[POST_ACTION] != NULL) {
          _new = action->action_PostRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_TimesRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL) {
          _new = action->action_PostRE[PRE_ACTION](me, me);
        }
        if (action->action_TimesRE[PRE_ACTION] != NULL) {
          _new = action->action_TimesRE[PRE_ACTION](me, me);
        }
        if (!action->skip_children_PostRE) {
          grammar_PostRE_re(me) = Traverse_copy_grammar_RegExpr (grammar_PostRE_re(me), action);
        }
        if (action->action_TimesRE[POST_ACTION] != NULL) {
          _new = action->action_TimesRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_PostRE[POST_ACTION] != NULL) {
          _new = action->action_PostRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_StringRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          _new = action->action_BasicRE[PRE_ACTION](me, me);
        }
        if (action->action_StringRE[PRE_ACTION] != NULL) {
          _new = action->action_StringRE[PRE_ACTION](me, me);
        }
        if (action->action_StringRE[POST_ACTION] != NULL) {
          _new = action->action_StringRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          _new = action->action_BasicRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_SOLRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          _new = action->action_BasicRE[PRE_ACTION](me, me);
        }
        if (action->action_SOLRE[PRE_ACTION] != NULL) {
          _new = action->action_SOLRE[PRE_ACTION](me, me);
        }
        if (action->action_SOLRE[POST_ACTION] != NULL) {
          _new = action->action_SOLRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          _new = action->action_BasicRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_EOLRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          _new = action->action_BasicRE[PRE_ACTION](me, me);
        }
        if (action->action_EOLRE[PRE_ACTION] != NULL) {
          _new = action->action_EOLRE[PRE_ACTION](me, me);
        }
        if (action->action_EOLRE[POST_ACTION] != NULL) {
          _new = action->action_EOLRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          _new = action->action_BasicRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_IdRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          _new = action->action_BasicRE[PRE_ACTION](me, me);
        }
        if (action->action_IdRE[PRE_ACTION] != NULL) {
          _new = action->action_IdRE[PRE_ACTION](me, me);
        }
        if (action->action_IdRE[POST_ACTION] != NULL) {
          _new = action->action_IdRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          _new = action->action_BasicRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_ParRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          _new = action->action_BasicRE[PRE_ACTION](me, me);
        }
        if (action->action_ParRE[PRE_ACTION] != NULL) {
          _new = action->action_ParRE[PRE_ACTION](me, me);
        }
        if (!action->skip_children_ParRE) {
          grammar_ParRE_re(me) = Traverse_copy_grammar_RegExpr (grammar_ParRE_re(me), action);
        }
        if (action->action_ParRE[POST_ACTION] != NULL) {
          _new = action->action_ParRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          _new = action->action_BasicRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_AnyRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          _new = action->action_BasicRE[PRE_ACTION](me, me);
        }
        if (action->action_AnyRE[PRE_ACTION] != NULL) {
          _new = action->action_AnyRE[PRE_ACTION](me, me);
        }
        if (action->action_AnyRE[POST_ACTION] != NULL) {
          _new = action->action_AnyRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          _new = action->action_BasicRE[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_RegExpr[POST_ACTION] != NULL) {
    me = action->action_RegExpr[POST_ACTION](me, _old);
  }
  return me;
}

grammar_Parser Traverse_copy_grammar_Parser (grammar_Parser me, copy_grammar_TraverseTable action)
{ grammar_Parser _new = me, _old = me;
  if (action->action_Parser[PRE_ACTION] != NULL) {
    _new = action->action_Parser[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (grammar_Parser)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Parser) {
    grammar_Parser_rules(me) = Traverse_copy_List_grammar_ProdRule (grammar_Parser_rules(me), action);
  }
  }
  if (action->action_Parser[POST_ACTION] != NULL) {
    me = action->action_Parser[POST_ACTION](me, _old);
  }
  return me;
}

grammar_ProdRule Traverse_copy_grammar_ProdRule (grammar_ProdRule me, copy_grammar_TraverseTable action)
{ grammar_ProdRule _new = me, _old = me;
  if (action->action_ProdRule[PRE_ACTION] != NULL) {
    _new = action->action_ProdRule[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (grammar_ProdRule)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { switch (grammar_ProdRule_tag(me)) {
      case grammar_NT_Rule_kind:
        if (action->action_NT_Rule[PRE_ACTION] != NULL) {
          _new = action->action_NT_Rule[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            grammar_ProdRule_fields(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            grammar_NT_Rule_nt(me) = NULL;
            grammar_NT_Rule_alt(me) = NULL;
            grammar_NT_Rule_rhs(me) = NULL;
            grammar_NT_Rule_fields(me) = NULL;
          }
        if (action->action_NT_Rule[POST_ACTION] != NULL) {
          _new = action->action_NT_Rule[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_Import_Rule_kind:
        if (action->action_Import_Rule[PRE_ACTION] != NULL) {
          _new = action->action_Import_Rule[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            grammar_ProdRule_fields(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            grammar_Import_Rule_type(me) = NULL;
            grammar_Import_Rule_grammar(me) = NULL;
            grammar_Import_Rule_imp(me) = NULL;
          }
        if (action->action_Import_Rule[POST_ACTION] != NULL) {
          _new = action->action_Import_Rule[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
      case grammar_Extra_Rule_kind:
        if (action->action_Extra_Rule[PRE_ACTION] != NULL) {
          _new = action->action_Extra_Rule[PRE_ACTION](me, me);
        }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            grammar_ProdRule_fields(me) = NULL;
          }
          if (action->clear_back_edges == Copy_and_Clear || action->clear_back_edges == Just_Clear) {
            grammar_Extra_Rule_sym(me) = NULL;
          }
        if (action->action_Extra_Rule[POST_ACTION] != NULL) {
          _new = action->action_Extra_Rule[POST_ACTION](me, me);
          if (_new != NULL) return _new;
        }
        break;
    }
  }
  if (action->action_ProdRule[POST_ACTION] != NULL) {
    me = action->action_ProdRule[POST_ACTION](me, _old);
  }
  return me;
}

grammar_Scope Traverse_copy_grammar_Scope (grammar_Scope me, copy_grammar_TraverseTable action)
{ grammar_Scope _new = me, _old = me;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    _new = action->action_Scope[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (grammar_Scope)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_Scope) {
    grammar_Scope_next(me) = Traverse_copy_grammar_Scope (grammar_Scope_next(me), action);
  }
  }
  if (action->action_Scope[POST_ACTION] != NULL) {
    me = action->action_Scope[POST_ACTION](me, _old);
  }
  return me;
}

List_grammar_ProdRule Traverse_copy_List_grammar_ProdRule (List_grammar_ProdRule me, copy_grammar_TraverseTable action)
{ List_grammar_ProdRule _new = me, _old = me;
  if (action->action_List_ProdRule[PRE_ACTION] != NULL) {
    _new = action->action_List_ProdRule[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_grammar_ProdRule)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_ProdRule) {
    List_grammar_ProdRule_data(me) = Traverse_copy_grammar_ProdRule (List_grammar_ProdRule_data(me), action);
    List_grammar_ProdRule_next(me) = Traverse_copy_List_grammar_ProdRule (List_grammar_ProdRule_next(me), action);
  }
  }
  if (action->action_List_ProdRule[POST_ACTION] != NULL) {
    me = action->action_List_ProdRule[POST_ACTION](me, _old);
  }
  return me;
}

List_grammar_Token Traverse_copy_List_grammar_Token (List_grammar_Token me, copy_grammar_TraverseTable action)
{ List_grammar_Token _new = me, _old = me;
  if (action->action_List_Token[PRE_ACTION] != NULL) {
    _new = action->action_List_Token[PRE_ACTION](me, me);
    if (_new != NULL) return _new;
  }
  if (me == NULL) return me;
  if (action->clear_back_edges == Just_Copy || action->clear_back_edges == Copy_and_Clear)
  { _new = (List_grammar_Token)fe_malloc (sizeof(*_new));
    *_new = *me;
  }
  me = _new;
  if (me != NULL)
  { 
  if (!action->skip_children_List_Token) {
    List_grammar_Token_data(me) = Traverse_copy_grammar_Token (List_grammar_Token_data(me), action);
    List_grammar_Token_next(me) = Traverse_copy_List_grammar_Token (List_grammar_Token_next(me), action);
  }
  }
  if (action->action_List_Token[POST_ACTION] != NULL) {
    me = action->action_List_Token[POST_ACTION](me, _old);
  }
  return me;
}

int Traverse_compare_grammar_grammar (grammar_grammar x, grammar_grammar y, compare_grammar_TraverseTable action)
{ int comp = 0;
  if (action->action_grammar[PRE_ACTION] != NULL) {
    return action->action_grammar[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_grammar) {
    if ((comp = Traverse_compare_grammar_Scanner (grammar_grammar_scanner(x),grammar_grammar_scanner(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_grammar_Parser (grammar_grammar_parser(x),grammar_grammar_parser(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_grammar_Scanner (grammar_Scanner x, grammar_Scanner y, compare_grammar_TraverseTable action)
{ int comp = 0;
  if (action->action_Scanner[PRE_ACTION] != NULL) {
    return action->action_Scanner[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Scanner) {
    if ((comp = Traverse_compare_List_grammar_Token (grammar_Scanner_tokens(x),grammar_Scanner_tokens(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_grammar_Token (grammar_Token x, grammar_Token y, compare_grammar_TraverseTable action)
{ int comp = 0;
  if (action->action_Token[PRE_ACTION] != NULL) {
    return action->action_Token[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Token) {
    if ((comp = Traverse_compare_grammar_RegExpr (grammar_Token_re(x),grammar_Token_re(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_String (grammar_Token_actions(x),grammar_Token_actions(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_grammar_RegExpr (grammar_RegExpr x, grammar_RegExpr y, compare_grammar_TraverseTable action)
{ int comp = 0;
  if (action->action_RegExpr[PRE_ACTION] != NULL) {
    return action->action_RegExpr[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (grammar_RegExpr_tag(x) < grammar_RegExpr_tag(y)) return -1;
  if (grammar_RegExpr_tag(x) > grammar_RegExpr_tag(y)) return 1;;
  switch (grammar_RegExpr_tag(x)) {
      case grammar_ChoiceRE_kind:
        if (action->action_ChoiceRE[PRE_ACTION] != NULL) {
          return action->action_ChoiceRE[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ChoiceRE) {
          if ((comp = Traverse_compare_grammar_RegExpr (grammar_ChoiceRE_head(x),grammar_ChoiceRE_head(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_grammar_RegExpr (grammar_ChoiceRE_tail(x),grammar_ChoiceRE_tail(y), action)) != 0) return comp;
        }
        if (action->action_ChoiceRE[POST_ACTION] != NULL) {
          return action->action_ChoiceRE[POST_ACTION](x, y);
        }
        break;
      case grammar_SeqRE_kind:
        if (action->action_SeqRE[PRE_ACTION] != NULL) {
          return action->action_SeqRE[PRE_ACTION](x, y);
        }
        if (!action->skip_children_SeqRE) {
          if ((comp = Traverse_compare_grammar_RegExpr (grammar_SeqRE_head(x),grammar_SeqRE_head(y), action)) != 0) return comp;
          if ((comp = Traverse_compare_grammar_RegExpr (grammar_SeqRE_tail(x),grammar_SeqRE_tail(y), action)) != 0) return comp;
        }
        if (action->action_SeqRE[POST_ACTION] != NULL) {
          return action->action_SeqRE[POST_ACTION](x, y);
        }
        break;
      case grammar_OptRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL) {
          return action->action_PostRE[PRE_ACTION](x, y);
        }
        if (action->action_OptRE[PRE_ACTION] != NULL) {
          return action->action_OptRE[PRE_ACTION](x, y);
        }
        if (!action->skip_children_PostRE) {
          if ((comp = Traverse_compare_grammar_RegExpr (grammar_PostRE_re(x),grammar_PostRE_re(y), action)) != 0) return comp;
        }
        if (action->action_OptRE[POST_ACTION] != NULL) {
          return action->action_OptRE[POST_ACTION](x, y);
        }
        if (action->action_PostRE[POST_ACTION] != NULL) {
          return action->action_PostRE[POST_ACTION](x, y);
        }
        break;
      case grammar_PlusRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL) {
          return action->action_PostRE[PRE_ACTION](x, y);
        }
        if (action->action_PlusRE[PRE_ACTION] != NULL) {
          return action->action_PlusRE[PRE_ACTION](x, y);
        }
        if (!action->skip_children_PostRE) {
          if ((comp = Traverse_compare_grammar_RegExpr (grammar_PostRE_re(x),grammar_PostRE_re(y), action)) != 0) return comp;
        }
        if (action->action_PlusRE[POST_ACTION] != NULL) {
          return action->action_PlusRE[POST_ACTION](x, y);
        }
        if (action->action_PostRE[POST_ACTION] != NULL) {
          return action->action_PostRE[POST_ACTION](x, y);
        }
        break;
      case grammar_TimesRE_kind:
        if (action->action_PostRE[PRE_ACTION] != NULL) {
          return action->action_PostRE[PRE_ACTION](x, y);
        }
        if (action->action_TimesRE[PRE_ACTION] != NULL) {
          return action->action_TimesRE[PRE_ACTION](x, y);
        }
        if (!action->skip_children_PostRE) {
          if ((comp = Traverse_compare_grammar_RegExpr (grammar_PostRE_re(x),grammar_PostRE_re(y), action)) != 0) return comp;
        }
        if (action->action_TimesRE[POST_ACTION] != NULL) {
          return action->action_TimesRE[POST_ACTION](x, y);
        }
        if (action->action_PostRE[POST_ACTION] != NULL) {
          return action->action_PostRE[POST_ACTION](x, y);
        }
        break;
      case grammar_StringRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          return action->action_BasicRE[PRE_ACTION](x, y);
        }
        if (action->action_StringRE[PRE_ACTION] != NULL) {
          return action->action_StringRE[PRE_ACTION](x, y);
        }
        if (!action->skip_children_StringRE) {
          if ((comp = Traverse_compare_String (grammar_StringRE_s(x),grammar_StringRE_s(y), action)) != 0) return comp;
        }
        if (action->action_StringRE[POST_ACTION] != NULL) {
          return action->action_StringRE[POST_ACTION](x, y);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          return action->action_BasicRE[POST_ACTION](x, y);
        }
        break;
      case grammar_SOLRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          return action->action_BasicRE[PRE_ACTION](x, y);
        }
        if (action->action_SOLRE[PRE_ACTION] != NULL) {
          return action->action_SOLRE[PRE_ACTION](x, y);
        }
        if (action->action_SOLRE[POST_ACTION] != NULL) {
          return action->action_SOLRE[POST_ACTION](x, y);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          return action->action_BasicRE[POST_ACTION](x, y);
        }
        break;
      case grammar_EOLRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          return action->action_BasicRE[PRE_ACTION](x, y);
        }
        if (action->action_EOLRE[PRE_ACTION] != NULL) {
          return action->action_EOLRE[PRE_ACTION](x, y);
        }
        if (action->action_EOLRE[POST_ACTION] != NULL) {
          return action->action_EOLRE[POST_ACTION](x, y);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          return action->action_BasicRE[POST_ACTION](x, y);
        }
        break;
      case grammar_IdRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          return action->action_BasicRE[PRE_ACTION](x, y);
        }
        if (action->action_IdRE[PRE_ACTION] != NULL) {
          return action->action_IdRE[PRE_ACTION](x, y);
        }
        if (!action->skip_children_IdRE) {
          if ((comp = Traverse_compare_Ident (grammar_IdRE_id(x),grammar_IdRE_id(y), action)) != 0) return comp;
        }
        if (action->action_IdRE[POST_ACTION] != NULL) {
          return action->action_IdRE[POST_ACTION](x, y);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          return action->action_BasicRE[POST_ACTION](x, y);
        }
        break;
      case grammar_ParRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          return action->action_BasicRE[PRE_ACTION](x, y);
        }
        if (action->action_ParRE[PRE_ACTION] != NULL) {
          return action->action_ParRE[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ParRE) {
          if ((comp = Traverse_compare_grammar_RegExpr (grammar_ParRE_re(x),grammar_ParRE_re(y), action)) != 0) return comp;
        }
        if (action->action_ParRE[POST_ACTION] != NULL) {
          return action->action_ParRE[POST_ACTION](x, y);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          return action->action_BasicRE[POST_ACTION](x, y);
        }
        break;
      case grammar_AnyRE_kind:
        if (action->action_BasicRE[PRE_ACTION] != NULL) {
          return action->action_BasicRE[PRE_ACTION](x, y);
        }
        if (action->action_AnyRE[PRE_ACTION] != NULL) {
          return action->action_AnyRE[PRE_ACTION](x, y);
        }
        if (action->action_AnyRE[POST_ACTION] != NULL) {
          return action->action_AnyRE[POST_ACTION](x, y);
        }
        if (action->action_BasicRE[POST_ACTION] != NULL) {
          return action->action_BasicRE[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_grammar_Parser (grammar_Parser x, grammar_Parser y, compare_grammar_TraverseTable action)
{ int comp = 0;
  if (action->action_Parser[PRE_ACTION] != NULL) {
    return action->action_Parser[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Parser) {
    if ((comp = Traverse_compare_List_grammar_ProdRule (grammar_Parser_rules(x),grammar_Parser_rules(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_grammar_ProdRule (grammar_ProdRule x, grammar_ProdRule y, compare_grammar_TraverseTable action)
{ int comp = 0;
  if (action->action_ProdRule[PRE_ACTION] != NULL) {
    return action->action_ProdRule[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;
  if (grammar_ProdRule_tag(x) < grammar_ProdRule_tag(y)) return -1;
  if (grammar_ProdRule_tag(x) > grammar_ProdRule_tag(y)) return 1;;
  switch (grammar_ProdRule_tag(x)) {
      case grammar_NT_Rule_kind:
        if (action->action_NT_Rule[PRE_ACTION] != NULL) {
          return action->action_NT_Rule[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ProdRule) {
          if ((comp = Traverse_compare_Ident (grammar_ProdRule_lhs(x),grammar_ProdRule_lhs(y), action)) != 0) return comp;
        }
        if (action->action_NT_Rule[POST_ACTION] != NULL) {
          return action->action_NT_Rule[POST_ACTION](x, y);
        }
        break;
      case grammar_Import_Rule_kind:
        if (action->action_Import_Rule[PRE_ACTION] != NULL) {
          return action->action_Import_Rule[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ProdRule) {
          if ((comp = Traverse_compare_Ident (grammar_ProdRule_lhs(x),grammar_ProdRule_lhs(y), action)) != 0) return comp;
        }
        if (action->action_Import_Rule[POST_ACTION] != NULL) {
          return action->action_Import_Rule[POST_ACTION](x, y);
        }
        break;
      case grammar_Extra_Rule_kind:
        if (action->action_Extra_Rule[PRE_ACTION] != NULL) {
          return action->action_Extra_Rule[PRE_ACTION](x, y);
        }
        if (!action->skip_children_ProdRule) {
          if ((comp = Traverse_compare_Ident (grammar_ProdRule_lhs(x),grammar_ProdRule_lhs(y), action)) != 0) return comp;
        }
        if (action->action_Extra_Rule[POST_ACTION] != NULL) {
          return action->action_Extra_Rule[POST_ACTION](x, y);
        }
        break;
  }
  return comp;
}

int Traverse_compare_grammar_Scope (grammar_Scope x, grammar_Scope y, compare_grammar_TraverseTable action)
{ int comp = 0;
  if (action->action_Scope[PRE_ACTION] != NULL) {
    return action->action_Scope[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_Scope) {
    if ((comp = Traverse_compare_grammar_Scope (grammar_Scope_next(x),grammar_Scope_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_grammar_ProdRule (List_grammar_ProdRule x, List_grammar_ProdRule y, compare_grammar_TraverseTable action)
{ int comp = 0;
  if (action->action_List_ProdRule[PRE_ACTION] != NULL) {
    return action->action_List_ProdRule[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_ProdRule) {
    if ((comp = Traverse_compare_grammar_ProdRule (List_grammar_ProdRule_data(x),List_grammar_ProdRule_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_grammar_ProdRule (List_grammar_ProdRule_next(x),List_grammar_ProdRule_next(y), action)) != 0) return comp;
  }
  return comp;
}

int Traverse_compare_List_grammar_Token (List_grammar_Token x, List_grammar_Token y, compare_grammar_TraverseTable action)
{ int comp = 0;
  if (action->action_List_Token[PRE_ACTION] != NULL) {
    return action->action_List_Token[PRE_ACTION](x, y);
  }
  if (x == y) return 0;
  if (x == NULL && y != NULL) return -1;
  if (x != NULL && y == NULL) return 1;

  if (!action->skip_children_List_Token) {
    if ((comp = Traverse_compare_grammar_Token (List_grammar_Token_data(x),List_grammar_Token_data(y), action)) != 0) return comp;
    if ((comp = Traverse_compare_List_grammar_Token (List_grammar_Token_next(x),List_grammar_Token_next(y), action)) != 0) return comp;
  }
  return comp;
}

struct s_grammar_TraverseTable grammar_scope_actions = {

  Traverse_Accumulate,
  { NULL,	NULL }, FALSE,	/* grammar_grammar */
  { NULL,	NULL }, FALSE,	/* grammar_Scanner */
  { NULL,	NULL }, FALSE,	/* grammar_Token */
  { NULL,	NULL }, FALSE,	/* grammar_RegExpr */
  { NULL,	NULL }, FALSE,	/* grammar_ChoiceRE */
  { NULL,	NULL }, FALSE,	/* grammar_SeqRE */
  { NULL,	NULL }, FALSE,	/* grammar_PostRE */
  { NULL,	NULL }, FALSE,	/* grammar_OptRE */
  { NULL,	NULL }, FALSE,	/* grammar_PlusRE */
  { NULL,	NULL }, FALSE,	/* grammar_TimesRE */
  { NULL,	NULL }, FALSE,	/* grammar_BasicRE */
  { NULL,	NULL }, FALSE,	/* grammar_StringRE */
  { NULL,	NULL }, FALSE,	/* grammar_SOLRE */
  { NULL,	NULL }, FALSE,	/* grammar_EOLRE */
  { NULL,	NULL }, FALSE,	/* grammar_IdRE */
  { NULL,	NULL }, FALSE,	/* grammar_ParRE */
  { NULL,	NULL }, FALSE,	/* grammar_AnyRE */
  { NULL,	NULL }, FALSE,	/* grammar_Parser */
  { NULL,	NULL }, FALSE,	/* grammar_ProdRule */
  { NULL,	NULL }, FALSE,	/* grammar_NT_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Import_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Extra_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Scope */
  { NULL,	NULL }, FALSE,	/* List_grammar_ProdRule */
  { NULL,	NULL }, FALSE,	/* List_grammar_Token */
};

static void Defining_grammar_grammar (grammar_grammar me)
{
  if (me==NULL) return;
}

static void Defining_grammar_Scanner (grammar_Scanner me)
{
  if (me==NULL) return;
}

static void Defining_grammar_Token (grammar_Token me)
{
  if (me==NULL) return;
}

static void Defining_grammar_RegExpr (grammar_RegExpr me)
{
  if (me==NULL) return;
}

static void Defining_grammar_Parser (grammar_Parser me)
{
  if (me==NULL) return;
}

static void Defining_grammar_ProdRule (grammar_ProdRule me)
{
  if (me==NULL) return;
}

struct s_void_grammar_TraverseTable grammar_defining_actions = {

  { NULL,	(void*)Defining_grammar_grammar }, FALSE,	/* grammar_grammar */
  { NULL,	(void*)Defining_grammar_Scanner }, FALSE,	/* grammar_Scanner */
  { NULL,	(void*)Defining_grammar_Token }, FALSE,	/* grammar_Token */
  { NULL,	(void*)Defining_grammar_RegExpr }, FALSE,	/* grammar_RegExpr */
  { NULL,	NULL }, FALSE,	/* grammar_ChoiceRE */
  { NULL,	NULL }, FALSE,	/* grammar_SeqRE */
  { NULL,	NULL }, FALSE,	/* grammar_PostRE */
  { NULL,	NULL }, FALSE,	/* grammar_OptRE */
  { NULL,	NULL }, FALSE,	/* grammar_PlusRE */
  { NULL,	NULL }, FALSE,	/* grammar_TimesRE */
  { NULL,	NULL }, FALSE,	/* grammar_BasicRE */
  { NULL,	NULL }, FALSE,	/* grammar_StringRE */
  { NULL,	NULL }, FALSE,	/* grammar_SOLRE */
  { NULL,	NULL }, FALSE,	/* grammar_EOLRE */
  { NULL,	NULL }, FALSE,	/* grammar_IdRE */
  { NULL,	NULL }, FALSE,	/* grammar_ParRE */
  { NULL,	NULL }, FALSE,	/* grammar_AnyRE */
  { NULL,	(void*)Defining_grammar_Parser }, FALSE,	/* grammar_Parser */
  { NULL,	(void*)Defining_grammar_ProdRule }, FALSE,	/* grammar_ProdRule */
  { NULL,	NULL }, FALSE,	/* grammar_NT_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Import_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Extra_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Scope */
  { NULL,	NULL }, FALSE,	/* List_grammar_ProdRule */
  { NULL,	NULL }, FALSE,	/* List_grammar_Token */
};

struct s_void_grammar_TraverseTable grammar_applied_actions = {

  { NULL,	NULL }, FALSE,	/* grammar_grammar */
  { NULL,	NULL }, FALSE,	/* grammar_Scanner */
  { NULL,	NULL }, FALSE,	/* grammar_Token */
  { NULL,	NULL }, FALSE,	/* grammar_RegExpr */
  { NULL,	NULL }, FALSE,	/* grammar_ChoiceRE */
  { NULL,	NULL }, FALSE,	/* grammar_SeqRE */
  { NULL,	NULL }, FALSE,	/* grammar_PostRE */
  { NULL,	NULL }, FALSE,	/* grammar_OptRE */
  { NULL,	NULL }, FALSE,	/* grammar_PlusRE */
  { NULL,	NULL }, FALSE,	/* grammar_TimesRE */
  { NULL,	NULL }, FALSE,	/* grammar_BasicRE */
  { NULL,	NULL }, FALSE,	/* grammar_StringRE */
  { NULL,	NULL }, FALSE,	/* grammar_SOLRE */
  { NULL,	NULL }, FALSE,	/* grammar_EOLRE */
  { NULL,	NULL }, FALSE,	/* grammar_IdRE */
  { NULL,	NULL }, FALSE,	/* grammar_ParRE */
  { NULL,	NULL }, FALSE,	/* grammar_AnyRE */
  { NULL,	NULL }, FALSE,	/* grammar_Parser */
  { NULL,	NULL }, FALSE,	/* grammar_ProdRule */
  { NULL,	NULL }, FALSE,	/* grammar_NT_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Import_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Extra_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Scope */
  { NULL,	NULL }, FALSE,	/* List_grammar_ProdRule */
  { NULL,	NULL }, FALSE,	/* List_grammar_Token */
};

struct s_void_grammar_TraverseTable grammar_check_actions = {

  { NULL,	NULL }, FALSE,	/* grammar_grammar */
  { NULL,	NULL }, FALSE,	/* grammar_Scanner */
  { NULL,	NULL }, FALSE,	/* grammar_Token */
  { NULL,	NULL }, FALSE,	/* grammar_RegExpr */
  { NULL,	NULL }, FALSE,	/* grammar_ChoiceRE */
  { NULL,	NULL }, FALSE,	/* grammar_SeqRE */
  { NULL,	NULL }, FALSE,	/* grammar_PostRE */
  { NULL,	NULL }, FALSE,	/* grammar_OptRE */
  { NULL,	NULL }, FALSE,	/* grammar_PlusRE */
  { NULL,	NULL }, FALSE,	/* grammar_TimesRE */
  { NULL,	NULL }, FALSE,	/* grammar_BasicRE */
  { NULL,	NULL }, FALSE,	/* grammar_StringRE */
  { NULL,	NULL }, FALSE,	/* grammar_SOLRE */
  { NULL,	NULL }, FALSE,	/* grammar_EOLRE */
  { NULL,	NULL }, FALSE,	/* grammar_IdRE */
  { NULL,	NULL }, FALSE,	/* grammar_ParRE */
  { NULL,	NULL }, FALSE,	/* grammar_AnyRE */
  { NULL,	NULL }, FALSE,	/* grammar_Parser */
  { NULL,	NULL }, FALSE,	/* grammar_ProdRule */
  { NULL,	NULL }, FALSE,	/* grammar_NT_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Import_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Extra_Rule */
  { NULL,	NULL }, FALSE,	/* grammar_Scope */
  { NULL,	NULL }, FALSE,	/* List_grammar_ProdRule */
  { NULL,	NULL }, FALSE,	/* List_grammar_Token */
};

struct s_void_grammar_TraverseTable grammar_print_actions;

struct s_copy_grammar_TraverseTable grammar_copy_actions;

struct s_compare_grammar_TraverseTable grammar_compare_actions;

void grammar_fill_table (grammar_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_grammar[PRE_ACTION] = (void* (*) (grammar_grammar, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_grammar[POST_ACTION] = (void* (*) (grammar_grammar, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scanner[PRE_ACTION] = (void* (*) (grammar_Scanner, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scanner[POST_ACTION] = (void* (*) (grammar_Scanner, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Token[PRE_ACTION] = (void* (*) (grammar_Token, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Token[POST_ACTION] = (void* (*) (grammar_Token, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RegExpr[PRE_ACTION] = (void* (*) (grammar_RegExpr, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RegExpr[POST_ACTION] = (void* (*) (grammar_RegExpr, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ChoiceRE[PRE_ACTION] = (void* (*) (grammar_ChoiceRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ChoiceRE[POST_ACTION] = (void* (*) (grammar_ChoiceRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SeqRE[PRE_ACTION] = (void* (*) (grammar_SeqRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SeqRE[POST_ACTION] = (void* (*) (grammar_SeqRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PostRE[PRE_ACTION] = (void* (*) (grammar_PostRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PostRE[POST_ACTION] = (void* (*) (grammar_PostRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptRE[PRE_ACTION] = (void* (*) (grammar_OptRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptRE[POST_ACTION] = (void* (*) (grammar_OptRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlusRE[PRE_ACTION] = (void* (*) (grammar_PlusRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlusRE[POST_ACTION] = (void* (*) (grammar_PlusRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TimesRE[PRE_ACTION] = (void* (*) (grammar_TimesRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TimesRE[POST_ACTION] = (void* (*) (grammar_TimesRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicRE[PRE_ACTION] = (void* (*) (grammar_BasicRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicRE[POST_ACTION] = (void* (*) (grammar_BasicRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringRE[PRE_ACTION] = (void* (*) (grammar_StringRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringRE[POST_ACTION] = (void* (*) (grammar_StringRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SOLRE[PRE_ACTION] = (void* (*) (grammar_SOLRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SOLRE[POST_ACTION] = (void* (*) (grammar_SOLRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EOLRE[PRE_ACTION] = (void* (*) (grammar_EOLRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EOLRE[POST_ACTION] = (void* (*) (grammar_EOLRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdRE[PRE_ACTION] = (void* (*) (grammar_IdRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdRE[POST_ACTION] = (void* (*) (grammar_IdRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ParRE[PRE_ACTION] = (void* (*) (grammar_ParRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ParRE[POST_ACTION] = (void* (*) (grammar_ParRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AnyRE[PRE_ACTION] = (void* (*) (grammar_AnyRE, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AnyRE[POST_ACTION] = (void* (*) (grammar_AnyRE, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Parser[PRE_ACTION] = (void* (*) (grammar_Parser, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Parser[POST_ACTION] = (void* (*) (grammar_Parser, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ProdRule[PRE_ACTION] = (void* (*) (grammar_ProdRule, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ProdRule[POST_ACTION] = (void* (*) (grammar_ProdRule, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NT_Rule[PRE_ACTION] = (void* (*) (grammar_NT_Rule, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NT_Rule[POST_ACTION] = (void* (*) (grammar_NT_Rule, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Import_Rule[PRE_ACTION] = (void* (*) (grammar_Import_Rule, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Import_Rule[POST_ACTION] = (void* (*) (grammar_Import_Rule, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Extra_Rule[PRE_ACTION] = (void* (*) (grammar_Extra_Rule, void*))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Extra_Rule[POST_ACTION] = (void* (*) (grammar_Extra_Rule, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void* (*) (grammar_Scope, void*))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void* (*) (grammar_Scope, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ProdRule[PRE_ACTION] = (void* (*) (List_grammar_ProdRule, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ProdRule[POST_ACTION] = (void* (*) (List_grammar_ProdRule, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Token[PRE_ACTION] = (void* (*) (List_grammar_Token, void*))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Token[POST_ACTION] = (void* (*) (List_grammar_Token, void*))x;
}

void void_grammar_fill_table (void_grammar_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_grammar[PRE_ACTION] = (void (*) (grammar_grammar))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_grammar[POST_ACTION] = (void (*) (grammar_grammar))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scanner[PRE_ACTION] = (void (*) (grammar_Scanner))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scanner[POST_ACTION] = (void (*) (grammar_Scanner))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Token[PRE_ACTION] = (void (*) (grammar_Token))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Token[POST_ACTION] = (void (*) (grammar_Token))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RegExpr[PRE_ACTION] = (void (*) (grammar_RegExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RegExpr[POST_ACTION] = (void (*) (grammar_RegExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ChoiceRE[PRE_ACTION] = (void (*) (grammar_ChoiceRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ChoiceRE[POST_ACTION] = (void (*) (grammar_ChoiceRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SeqRE[PRE_ACTION] = (void (*) (grammar_SeqRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SeqRE[POST_ACTION] = (void (*) (grammar_SeqRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PostRE[PRE_ACTION] = (void (*) (grammar_PostRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PostRE[POST_ACTION] = (void (*) (grammar_PostRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptRE[PRE_ACTION] = (void (*) (grammar_OptRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptRE[POST_ACTION] = (void (*) (grammar_OptRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlusRE[PRE_ACTION] = (void (*) (grammar_PlusRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlusRE[POST_ACTION] = (void (*) (grammar_PlusRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TimesRE[PRE_ACTION] = (void (*) (grammar_TimesRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TimesRE[POST_ACTION] = (void (*) (grammar_TimesRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicRE[PRE_ACTION] = (void (*) (grammar_BasicRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicRE[POST_ACTION] = (void (*) (grammar_BasicRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringRE[PRE_ACTION] = (void (*) (grammar_StringRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringRE[POST_ACTION] = (void (*) (grammar_StringRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SOLRE[PRE_ACTION] = (void (*) (grammar_SOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SOLRE[POST_ACTION] = (void (*) (grammar_SOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EOLRE[PRE_ACTION] = (void (*) (grammar_EOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EOLRE[POST_ACTION] = (void (*) (grammar_EOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdRE[PRE_ACTION] = (void (*) (grammar_IdRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdRE[POST_ACTION] = (void (*) (grammar_IdRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ParRE[PRE_ACTION] = (void (*) (grammar_ParRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ParRE[POST_ACTION] = (void (*) (grammar_ParRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AnyRE[PRE_ACTION] = (void (*) (grammar_AnyRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AnyRE[POST_ACTION] = (void (*) (grammar_AnyRE))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Parser[PRE_ACTION] = (void (*) (grammar_Parser))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Parser[POST_ACTION] = (void (*) (grammar_Parser))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ProdRule[PRE_ACTION] = (void (*) (grammar_ProdRule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ProdRule[POST_ACTION] = (void (*) (grammar_ProdRule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NT_Rule[PRE_ACTION] = (void (*) (grammar_NT_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NT_Rule[POST_ACTION] = (void (*) (grammar_NT_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Import_Rule[PRE_ACTION] = (void (*) (grammar_Import_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Import_Rule[POST_ACTION] = (void (*) (grammar_Import_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Extra_Rule[PRE_ACTION] = (void (*) (grammar_Extra_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Extra_Rule[POST_ACTION] = (void (*) (grammar_Extra_Rule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (void (*) (grammar_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (void (*) (grammar_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ProdRule[PRE_ACTION] = (void (*) (List_grammar_ProdRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ProdRule[POST_ACTION] = (void (*) (List_grammar_ProdRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Token[PRE_ACTION] = (void (*) (List_grammar_Token))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Token[POST_ACTION] = (void (*) (List_grammar_Token))x;
}

void copy_grammar_fill_table (copy_grammar_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_grammar[PRE_ACTION] = (grammar_grammar (*) (grammar_grammar, grammar_grammar))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_grammar[POST_ACTION] = (grammar_grammar (*) (grammar_grammar, grammar_grammar))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scanner[PRE_ACTION] = (grammar_Scanner (*) (grammar_Scanner, grammar_Scanner))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scanner[POST_ACTION] = (grammar_Scanner (*) (grammar_Scanner, grammar_Scanner))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Token[PRE_ACTION] = (grammar_Token (*) (grammar_Token, grammar_Token))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Token[POST_ACTION] = (grammar_Token (*) (grammar_Token, grammar_Token))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RegExpr[PRE_ACTION] = (grammar_RegExpr (*) (grammar_RegExpr, grammar_RegExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RegExpr[POST_ACTION] = (grammar_RegExpr (*) (grammar_RegExpr, grammar_RegExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ChoiceRE[PRE_ACTION] = (grammar_ChoiceRE (*) (grammar_ChoiceRE, grammar_ChoiceRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ChoiceRE[POST_ACTION] = (grammar_ChoiceRE (*) (grammar_ChoiceRE, grammar_ChoiceRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SeqRE[PRE_ACTION] = (grammar_SeqRE (*) (grammar_SeqRE, grammar_SeqRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SeqRE[POST_ACTION] = (grammar_SeqRE (*) (grammar_SeqRE, grammar_SeqRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PostRE[PRE_ACTION] = (grammar_PostRE (*) (grammar_PostRE, grammar_PostRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PostRE[POST_ACTION] = (grammar_PostRE (*) (grammar_PostRE, grammar_PostRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptRE[PRE_ACTION] = (grammar_OptRE (*) (grammar_OptRE, grammar_OptRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptRE[POST_ACTION] = (grammar_OptRE (*) (grammar_OptRE, grammar_OptRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlusRE[PRE_ACTION] = (grammar_PlusRE (*) (grammar_PlusRE, grammar_PlusRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlusRE[POST_ACTION] = (grammar_PlusRE (*) (grammar_PlusRE, grammar_PlusRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TimesRE[PRE_ACTION] = (grammar_TimesRE (*) (grammar_TimesRE, grammar_TimesRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TimesRE[POST_ACTION] = (grammar_TimesRE (*) (grammar_TimesRE, grammar_TimesRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicRE[PRE_ACTION] = (grammar_BasicRE (*) (grammar_BasicRE, grammar_BasicRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicRE[POST_ACTION] = (grammar_BasicRE (*) (grammar_BasicRE, grammar_BasicRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringRE[PRE_ACTION] = (grammar_StringRE (*) (grammar_StringRE, grammar_StringRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringRE[POST_ACTION] = (grammar_StringRE (*) (grammar_StringRE, grammar_StringRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SOLRE[PRE_ACTION] = (grammar_SOLRE (*) (grammar_SOLRE, grammar_SOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SOLRE[POST_ACTION] = (grammar_SOLRE (*) (grammar_SOLRE, grammar_SOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EOLRE[PRE_ACTION] = (grammar_EOLRE (*) (grammar_EOLRE, grammar_EOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EOLRE[POST_ACTION] = (grammar_EOLRE (*) (grammar_EOLRE, grammar_EOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdRE[PRE_ACTION] = (grammar_IdRE (*) (grammar_IdRE, grammar_IdRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdRE[POST_ACTION] = (grammar_IdRE (*) (grammar_IdRE, grammar_IdRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ParRE[PRE_ACTION] = (grammar_ParRE (*) (grammar_ParRE, grammar_ParRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ParRE[POST_ACTION] = (grammar_ParRE (*) (grammar_ParRE, grammar_ParRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AnyRE[PRE_ACTION] = (grammar_AnyRE (*) (grammar_AnyRE, grammar_AnyRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AnyRE[POST_ACTION] = (grammar_AnyRE (*) (grammar_AnyRE, grammar_AnyRE))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Parser[PRE_ACTION] = (grammar_Parser (*) (grammar_Parser, grammar_Parser))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Parser[POST_ACTION] = (grammar_Parser (*) (grammar_Parser, grammar_Parser))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ProdRule[PRE_ACTION] = (grammar_ProdRule (*) (grammar_ProdRule, grammar_ProdRule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ProdRule[POST_ACTION] = (grammar_ProdRule (*) (grammar_ProdRule, grammar_ProdRule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NT_Rule[PRE_ACTION] = (grammar_NT_Rule (*) (grammar_NT_Rule, grammar_NT_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NT_Rule[POST_ACTION] = (grammar_NT_Rule (*) (grammar_NT_Rule, grammar_NT_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Import_Rule[PRE_ACTION] = (grammar_Import_Rule (*) (grammar_Import_Rule, grammar_Import_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Import_Rule[POST_ACTION] = (grammar_Import_Rule (*) (grammar_Import_Rule, grammar_Import_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Extra_Rule[PRE_ACTION] = (grammar_Extra_Rule (*) (grammar_Extra_Rule, grammar_Extra_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Extra_Rule[POST_ACTION] = (grammar_Extra_Rule (*) (grammar_Extra_Rule, grammar_Extra_Rule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (grammar_Scope (*) (grammar_Scope, grammar_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (grammar_Scope (*) (grammar_Scope, grammar_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ProdRule[PRE_ACTION] = (List_grammar_ProdRule (*) (List_grammar_ProdRule, List_grammar_ProdRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ProdRule[POST_ACTION] = (List_grammar_ProdRule (*) (List_grammar_ProdRule, List_grammar_ProdRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Token[PRE_ACTION] = (List_grammar_Token (*) (List_grammar_Token, List_grammar_Token))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Token[POST_ACTION] = (List_grammar_Token (*) (List_grammar_Token, List_grammar_Token))x;
}

void compare_grammar_fill_table (compare_grammar_TraverseTable t,void *(*f) (Bool e_num, Bool sub, Bool list, Bool opt, Bool memo, Int action))
{ void *x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_grammar[PRE_ACTION] = (int (*) (grammar_grammar, grammar_grammar))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_grammar[POST_ACTION] = (int (*) (grammar_grammar, grammar_grammar))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scanner[PRE_ACTION] = (int (*) (grammar_Scanner, grammar_Scanner))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scanner[POST_ACTION] = (int (*) (grammar_Scanner, grammar_Scanner))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Token[PRE_ACTION] = (int (*) (grammar_Token, grammar_Token))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Token[POST_ACTION] = (int (*) (grammar_Token, grammar_Token))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_RegExpr[PRE_ACTION] = (int (*) (grammar_RegExpr, grammar_RegExpr))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_RegExpr[POST_ACTION] = (int (*) (grammar_RegExpr, grammar_RegExpr))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ChoiceRE[PRE_ACTION] = (int (*) (grammar_ChoiceRE, grammar_ChoiceRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ChoiceRE[POST_ACTION] = (int (*) (grammar_ChoiceRE, grammar_ChoiceRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SeqRE[PRE_ACTION] = (int (*) (grammar_SeqRE, grammar_SeqRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SeqRE[POST_ACTION] = (int (*) (grammar_SeqRE, grammar_SeqRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PostRE[PRE_ACTION] = (int (*) (grammar_PostRE, grammar_PostRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PostRE[POST_ACTION] = (int (*) (grammar_PostRE, grammar_PostRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_OptRE[PRE_ACTION] = (int (*) (grammar_OptRE, grammar_OptRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_OptRE[POST_ACTION] = (int (*) (grammar_OptRE, grammar_OptRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_PlusRE[PRE_ACTION] = (int (*) (grammar_PlusRE, grammar_PlusRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_PlusRE[POST_ACTION] = (int (*) (grammar_PlusRE, grammar_PlusRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_TimesRE[PRE_ACTION] = (int (*) (grammar_TimesRE, grammar_TimesRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_TimesRE[POST_ACTION] = (int (*) (grammar_TimesRE, grammar_TimesRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_BasicRE[PRE_ACTION] = (int (*) (grammar_BasicRE, grammar_BasicRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_BasicRE[POST_ACTION] = (int (*) (grammar_BasicRE, grammar_BasicRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_StringRE[PRE_ACTION] = (int (*) (grammar_StringRE, grammar_StringRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_StringRE[POST_ACTION] = (int (*) (grammar_StringRE, grammar_StringRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_SOLRE[PRE_ACTION] = (int (*) (grammar_SOLRE, grammar_SOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_SOLRE[POST_ACTION] = (int (*) (grammar_SOLRE, grammar_SOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_EOLRE[PRE_ACTION] = (int (*) (grammar_EOLRE, grammar_EOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_EOLRE[POST_ACTION] = (int (*) (grammar_EOLRE, grammar_EOLRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_IdRE[PRE_ACTION] = (int (*) (grammar_IdRE, grammar_IdRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_IdRE[POST_ACTION] = (int (*) (grammar_IdRE, grammar_IdRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ParRE[PRE_ACTION] = (int (*) (grammar_ParRE, grammar_ParRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ParRE[POST_ACTION] = (int (*) (grammar_ParRE, grammar_ParRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_AnyRE[PRE_ACTION] = (int (*) (grammar_AnyRE, grammar_AnyRE))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_AnyRE[POST_ACTION] = (int (*) (grammar_AnyRE, grammar_AnyRE))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Parser[PRE_ACTION] = (int (*) (grammar_Parser, grammar_Parser))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Parser[POST_ACTION] = (int (*) (grammar_Parser, grammar_Parser))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_ProdRule[PRE_ACTION] = (int (*) (grammar_ProdRule, grammar_ProdRule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_ProdRule[POST_ACTION] = (int (*) (grammar_ProdRule, grammar_ProdRule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_NT_Rule[PRE_ACTION] = (int (*) (grammar_NT_Rule, grammar_NT_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_NT_Rule[POST_ACTION] = (int (*) (grammar_NT_Rule, grammar_NT_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Import_Rule[PRE_ACTION] = (int (*) (grammar_Import_Rule, grammar_Import_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Import_Rule[POST_ACTION] = (int (*) (grammar_Import_Rule, grammar_Import_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Extra_Rule[PRE_ACTION] = (int (*) (grammar_Extra_Rule, grammar_Extra_Rule))x;
  x = f (FALSE,TRUE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Extra_Rule[POST_ACTION] = (int (*) (grammar_Extra_Rule, grammar_Extra_Rule))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_Scope[PRE_ACTION] = (int (*) (grammar_Scope, grammar_Scope))x;
  x = f (FALSE,FALSE,FALSE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_Scope[POST_ACTION] = (int (*) (grammar_Scope, grammar_Scope))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_ProdRule[PRE_ACTION] = (int (*) (List_grammar_ProdRule, List_grammar_ProdRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_ProdRule[POST_ACTION] = (int (*) (List_grammar_ProdRule, List_grammar_ProdRule))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,PRE_ACTION);
  if (x!=NULL) t->action_List_Token[PRE_ACTION] = (int (*) (List_grammar_Token, List_grammar_Token))x;
  x = f (FALSE,FALSE,TRUE,FALSE,FALSE,POST_ACTION);
  if (x!=NULL) t->action_List_Token[POST_ACTION] = (int (*) (List_grammar_Token, List_grammar_Token))x;
}

grammar_NameSpaces grammar_namespaces[] = { -1 };

void Decorate_grammar (grammar_grammar r)
{
  if (grammar_namespaces[0]<0) Extend_namespaces (grammar_NUM_NAMESPACES, grammar_namespaces);
  grammar_root = r;
  if (NoDecorate) return;
  Traverse_grammar_grammar (r, &grammar_scope_actions, NULL);
  Traverse_void_grammar_grammar (r, &grammar_defining_actions);
  Traverse_void_grammar_grammar (r, &grammar_applied_actions);
  Traverse_void_grammar_grammar (r, &grammar_check_actions);
}
