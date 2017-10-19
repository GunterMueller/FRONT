#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "front/parse_support.h"
#include "front/mem.h"
#include "grammar_parse.h"
#include "grammar_lalr.h"

extern struct yy_buffer_state *grammar__scan_string (char *);
extern struct yy_buffer_state *grammar__scan_buffer (char *, size_t);
extern struct yy_buffer_state *grammar__create_buffer (FILE *, int);
extern void grammar__switch_to_buffer (struct yy_buffer_state *);
extern void grammar_push_buffer_state (struct yy_buffer_state *);
extern void grammar__delete_buffer (struct yy_buffer_state *);
extern int grammar_parse (void);

Bool grammar_use_lalr = FALSE;
extern int grammar_state_stack_depth;
static void grammar_parse_nt (char *nt, char *s)
{ char *t = (char*)fe_malloc(1+strlen(nt)+strlen(s)+3);
  struct yy_buffer_state *buf;  sprintf(t, "%s_%s %s", "%", nt, s);
  buf = grammar__scan_string (t);  grammar__switch_to_buffer (buf);
  grammar_parse();
  grammar__delete_buffer(buf);
}

static void *the_node;
void grammar_multi_action (void* n)
{ the_node = n; }

static void *grammar_parse_string (char *nt, char *s)
{
  the_node = NULL;
  grammar_parse_nt (nt, s);
  assert (first_sub_tree==NULL);
  return the_node;
}

static struct yy_buffer_state *dummy_state (void)
{
  static struct yy_buffer_state *state = NULL;
  if (!state) state = grammar__create_buffer (NULL,0);
  return state;
}

grammar_grammar Parse_grammar_grammar (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_grammar ();
  } else {
    return (grammar_grammar)grammar_parse_string ("grammar", s);
  }
}

grammar_Scanner Parse_grammar_Scanner (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_Scanner ();
  } else {
    return (grammar_Scanner)grammar_parse_string ("Scanner", s);
  }
}

grammar_Token Parse_grammar_Token (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_Token ();
  } else {
    return (grammar_Token)grammar_parse_string ("Token", s);
  }
}

grammar_RegExpr Parse_grammar_RegExpr (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_RegExpr ();
  } else {
    return (grammar_RegExpr)grammar_parse_string ("RegExpr", s);
  }
}

grammar_RegExpr Parse_grammar_ChoiceRE (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_ChoiceRE ();
  } else {
    return (grammar_RegExpr)grammar_parse_string ("ChoiceRE", s);
  }
}

grammar_RegExpr Parse_grammar_SeqRE (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_SeqRE ();
  } else {
    return (grammar_RegExpr)grammar_parse_string ("SeqRE", s);
  }
}

grammar_RegExpr Parse_grammar_PostRE (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_PostRE ();
  } else {
    return (grammar_RegExpr)grammar_parse_string ("PostRE", s);
  }
}

grammar_RegExpr Parse_grammar_BasicRE (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_BasicRE ();
  } else {
    return (grammar_RegExpr)grammar_parse_string ("BasicRE", s);
  }
}

String Parse_grammar_ScanAction (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_ScanAction ();
  } else {
    return (String)grammar_parse_string ("ScanAction", s);
  }
}

grammar_Parser Parse_grammar_Parser (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_Parser ();
  } else {
    return (grammar_Parser)grammar_parse_string ("Parser", s);
  }
}

grammar_ProdRule Parse_grammar_ProdRule (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_ProdRule ();
  } else {
    return (grammar_ProdRule)grammar_parse_string ("ProdRule", s);
  }
}

List_grammar_Token Parse_grammar_OPTMORE_Token (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_OPTMORE_Token ();
  } else {
    return (List_grammar_Token)grammar_parse_string ("OPTMORE_Token", s);
  }
}

List_String Parse_grammar_OPTMORE_ScanAction_semicolonsym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_OPTMORE_ScanAction_semicolonsym ();
  } else {
    return (List_String)grammar_parse_string ("OPTMORE_ScanAction_semicolonsym", s);
  }
}

List_grammar_ProdRule Parse_grammar_OPTMORE_ProdRule (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (grammar_use_lalr) {
    grammar__switch_to_buffer (grammar__scan_string (s));
    return Parse_state_grammar_OPTMORE_ProdRule ();
  } else {
    return (List_grammar_ProdRule)grammar_parse_string ("OPTMORE_ProdRule", s);
  }
}

