#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "front/parse_support.h"
#include "front/mem.h"
#include "front_parse.h"
#include "front_lalr.h"

extern struct yy_buffer_state *front__scan_string (char *);
extern struct yy_buffer_state *front__scan_buffer (char *, size_t);
extern struct yy_buffer_state *front__create_buffer (FILE *, int);
extern void front__switch_to_buffer (struct yy_buffer_state *);
extern void front_push_buffer_state (struct yy_buffer_state *);
extern void front__delete_buffer (struct yy_buffer_state *);
extern int front_parse (void);

Bool front_use_lalr = FALSE;
extern int front_state_stack_depth;
static void front_parse_nt (char *nt, char *s)
{ char *t = (char*)fe_malloc(1+strlen(nt)+strlen(s)+3);
  struct yy_buffer_state *buf;  sprintf(t, "%s_%s %s", "%", nt, s);
  buf = front__scan_string (t);  front__switch_to_buffer (buf);
  front_parse();
  front__delete_buffer(buf);
}

static void *the_node;
void front_multi_action (void* n)
{ the_node = n; }

static void *front_parse_string (char *nt, char *s)
{
  the_node = NULL;
  front_parse_nt (nt, s);
  assert (first_sub_tree==NULL);
  return the_node;
}

static struct yy_buffer_state *dummy_state (void)
{
  static struct yy_buffer_state *state = NULL;
  if (!state) state = front__create_buffer (NULL,0);
  return state;
}

front_front Parse_front_front (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_front ();
  } else {
    return (front_front)front_parse_string ("front", s);
  }
}

front_Import Parse_front_Import (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Import ();
  } else {
    return (front_Import)front_parse_string ("Import", s);
  }
}

List_front_ImportedNonTerminal Parse_front_ImportedNonTerminals (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ImportedNonTerminals ();
  } else {
    return (List_front_ImportedNonTerminal)front_parse_string ("ImportedNonTerminals", s);
  }
}

front_ImportedNonTerminal Parse_front_ImportedNonTerminal (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ImportedNonTerminal ();
  } else {
    return (front_ImportedNonTerminal)front_parse_string ("ImportedNonTerminal", s);
  }
}

List_front_NonTerminal Parse_front_NonTerminals (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_NonTerminals ();
  } else {
    return (List_front_NonTerminal)front_parse_string ("NonTerminals", s);
  }
}

front_NonTerminal Parse_front_NonTerminal (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_NonTerminal ();
  } else {
    return (front_NonTerminal)front_parse_string ("NonTerminal", s);
  }
}

front_Super Parse_front_Super (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Super ();
  } else {
    return (front_Super)front_parse_string ("Super", s);
  }
}

front_Rhs Parse_front_Rhs (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Rhs ();
  } else {
    return (front_Rhs)front_parse_string ("Rhs", s);
  }
}

front_Scoping Parse_front_Scoping (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Scoping ();
  } else {
    return (front_Scoping)front_parse_string ("Scoping", s);
  }
}

front_Alternative Parse_front_Alternative (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Alternative ();
  } else {
    return (front_Alternative)front_parse_string ("Alternative", s);
  }
}

front_Symbol Parse_front_Symbol (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Symbol ();
  } else {
    return (front_Symbol)front_parse_string ("Symbol", s);
  }
}

front_Symbol Parse_front_Symbol1 (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Symbol1 ();
  } else {
    return (front_Symbol)front_parse_string ("Symbol1", s);
  }
}

front_Symbol Parse_front_AltSymbol (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_AltSymbol ();
  } else {
    return (front_Symbol)front_parse_string ("AltSymbol", s);
  }
}

front_Symbol Parse_front_SymbolSeq (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_SymbolSeq ();
  } else {
    return (front_Symbol)front_parse_string ("SymbolSeq", s);
  }
}

front_And Parse_front_And (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_And ();
  } else {
    return (front_And)front_parse_string ("And", s);
  }
}

front_Or Parse_front_Or (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Or ();
  } else {
    return (front_Or)front_parse_string ("Or", s);
  }
}

front_Symbol Parse_front_Symbol2 (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Symbol2 ();
  } else {
    return (front_Symbol)front_parse_string ("Symbol2", s);
  }
}

front_Symbol Parse_front_SimpleSymbol (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_SimpleSymbol ();
  } else {
    return (front_Symbol)front_parse_string ("SimpleSymbol", s);
  }
}

front_Symbol Parse_front_IdSym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_IdSym ();
  } else {
    return (front_Symbol)front_parse_string ("IdSym", s);
  }
}

front_Type Parse_front_OptType (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_OptType ();
  } else {
    return (front_Type)front_parse_string ("OptType", s);
  }
}

front_Symbol Parse_front_DefiningSym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_DefiningSym ();
  } else {
    return (front_Symbol)front_parse_string ("DefiningSym", s);
  }
}

front_Expr Parse_front_ScopeExpr (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ScopeExpr ();
  } else {
    return (front_Expr)front_parse_string ("ScopeExpr", s);
  }
}

front_Defining_id Parse_front_Defining_id (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Defining_id ();
  } else {
    return (front_Defining_id)front_parse_string ("Defining_id", s);
  }
}

front_Define Parse_front_Define (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Define ();
  } else {
    return (front_Define)front_parse_string ("Define", s);
  }
}

front_Field Parse_front_Field (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Field ();
  } else {
    return (front_Field)front_parse_string ("Field", s);
  }
}

List_front_FieldInit Parse_front_FieldInits (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_FieldInits ();
  } else {
    return (List_front_FieldInit)front_parse_string ("FieldInits", s);
  }
}

front_FieldInit Parse_front_FieldInit (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_FieldInit ();
  } else {
    return (front_FieldInit)front_parse_string ("FieldInit", s);
  }
}

front_Type Parse_front_Type (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Type ();
  } else {
    return (front_Type)front_parse_string ("Type", s);
  }
}

front_Expr Parse_front_Expr (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Expr ();
  } else {
    return (front_Expr)front_parse_string ("Expr", s);
  }
}

front_Expr Parse_front_MonExpr1 (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_MonExpr1 ();
  } else {
    return (front_Expr)front_parse_string ("MonExpr1", s);
  }
}

front_Expr Parse_front_SimpleExpr (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_SimpleExpr ();
  } else {
    return (front_Expr)front_parse_string ("SimpleExpr", s);
  }
}

String Parse_front_StringOrKeyword (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_StringOrKeyword ();
  } else {
    return (String)front_parse_string ("StringOrKeyword", s);
  }
}

front_Check Parse_front_Check (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Check ();
  } else {
    return (front_Check)front_parse_string ("Check", s);
  }
}

List_front_NameSpace Parse_front_NameSpaceList (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_NameSpaceList ();
  } else {
    return (List_front_NameSpace)front_parse_string ("NameSpaceList", s);
  }
}

List_front_Expr Parse_front_ExprList (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ExprList ();
  } else {
    return (List_front_Expr)front_parse_string ("ExprList", s);
  }
}

List_Ident Parse_front_IdentList (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_IdentList ();
  } else {
    return (List_Ident)front_parse_string ("IdentList", s);
  }
}

List_front_Type Parse_front_TypeList (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_TypeList ();
  } else {
    return (List_front_Type)front_parse_string ("TypeList", s);
  }
}

front_Alternator Parse_front_Alternator (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Alternator ();
  } else {
    return (front_Alternator)front_parse_string ("Alternator", s);
  }
}

front_ScanInfo Parse_front_ScanInfo (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ScanInfo ();
  } else {
    return (front_ScanInfo)front_parse_string ("ScanInfo", s);
  }
}

front_Defines Parse_front_Defines (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Defines ();
  } else {
    return (front_Defines)front_parse_string ("Defines", s);
  }
}

front_NameSpace Parse_front_NameSpace (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_NameSpace ();
  } else {
    return (front_NameSpace)front_parse_string ("NameSpace", s);
  }
}

Ident Parse_front_Oper (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_Oper ();
  } else {
    return (Ident)front_parse_string ("Oper", s);
  }
}

front_NameOrField Parse_front_NameOrField (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_NameOrField ();
  } else {
    return (front_NameOrField)front_parse_string ("NameOrField", s);
  }
}

List_front_Import Parse_front_OPTMORE_Import (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_OPTMORE_Import ();
  } else {
    return (List_front_Import)front_parse_string ("OPTMORE_Import", s);
  }
}

List_front_ImportedNonTerminal Parse_front_ALT_ImportedNonTerminal_SEP_commasym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ALT_ImportedNonTerminal_SEP_commasym ();
  } else {
    return (List_front_ImportedNonTerminal)front_parse_string ("ALT_ImportedNonTerminal_SEP_commasym", s);
  }
}

List_front_NonTerminal Parse_front_MORE_NonTerminal (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_MORE_NonTerminal ();
  } else {
    return (List_front_NonTerminal)front_parse_string ("MORE_NonTerminal", s);
  }
}

List_front_Scoping Parse_front_OPTMORE_Scoping (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_OPTMORE_Scoping ();
  } else {
    return (List_front_Scoping)front_parse_string ("OPTMORE_Scoping", s);
  }
}

List_front_Check Parse_front_OPTMORE_Check (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_OPTMORE_Check ();
  } else {
    return (List_front_Check)front_parse_string ("OPTMORE_Check", s);
  }
}

List_front_Symbol Parse_front_MORE_Symbol (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_MORE_Symbol ();
  } else {
    return (List_front_Symbol)front_parse_string ("MORE_Symbol", s);
  }
}

List_front_FieldInit Parse_front_ALT_FieldInit_SEP_commasym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ALT_FieldInit_SEP_commasym ();
  } else {
    return (List_front_FieldInit)front_parse_string ("ALT_FieldInit_SEP_commasym", s);
  }
}

List_Ident Parse_front_OPTMORE_Oper (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_OPTMORE_Oper ();
  } else {
    return (List_Ident)front_parse_string ("OPTMORE_Oper", s);
  }
}

List_front_Expr Parse_front_MORE_MonExpr1 (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_MORE_MonExpr1 ();
  } else {
    return (List_front_Expr)front_parse_string ("MORE_MonExpr1", s);
  }
}

List_front_NameSpace Parse_front_ALT_NameSpace_SEP_commasym_SP (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ALT_NameSpace_SEP_commasym_SP ();
  } else {
    return (List_front_NameSpace)front_parse_string ("ALT_NameSpace_SEP_commasym_SP", s);
  }
}

List_front_Expr Parse_front_ALT_Expr_SEP_commasym_SP (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ALT_Expr_SEP_commasym_SP ();
  } else {
    return (List_front_Expr)front_parse_string ("ALT_Expr_SEP_commasym_SP", s);
  }
}

List_Ident Parse_front_ALT_Identsym_SEP_commasym_SP (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ALT_Identsym_SEP_commasym_SP ();
  } else {
    return (List_Ident)front_parse_string ("ALT_Identsym_SEP_commasym_SP", s);
  }
}

List_front_Type Parse_front_ALT_Type_SEP_commasym_SP (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (front_use_lalr) {
    front__switch_to_buffer (front__scan_string (s));
    return Parse_state_front_ALT_Type_SEP_commasym_SP ();
  } else {
    return (List_front_Type)front_parse_string ("ALT_Type_SEP_commasym_SP", s);
  }
}

