#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "front/parse_support.h"
#include "front/mem.h"
#include "egg_parse.h"
#include "egg_lalr.h"

extern struct yy_buffer_state *egg__scan_string (char *);
extern struct yy_buffer_state *egg__scan_buffer (char *, size_t);
extern struct yy_buffer_state *egg__create_buffer (FILE *, int);
extern void egg__switch_to_buffer (struct yy_buffer_state *);
extern void egg_push_buffer_state (struct yy_buffer_state *);
extern void egg__delete_buffer (struct yy_buffer_state *);
extern int egg_parse (void);

Bool egg_use_lalr = FALSE;
extern int egg_state_stack_depth;
static void egg_parse_nt (char *nt, char *s)
{ char *t = (char*)fe_malloc(1+strlen(nt)+strlen(s)+3);
  struct yy_buffer_state *buf;  sprintf(t, "%s_%s %s", "%", nt, s);
  buf = egg__scan_string (t);  egg__switch_to_buffer (buf);
  egg_parse();
  egg__delete_buffer(buf);
}

static void *the_node;
void egg_multi_action (void* n)
{ the_node = n; }

static void *egg_parse_string (char *nt, char *s)
{
  the_node = NULL;
  egg_parse_nt (nt, s);
  assert (first_sub_tree==NULL);
  return the_node;
}

static struct yy_buffer_state *dummy_state (void)
{
  static struct yy_buffer_state *state = NULL;
  if (!state) state = egg__create_buffer (NULL,0);
  return state;
}

egg_egg Parse_egg_egg (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_egg ();
  } else {
    return (egg_egg)egg_parse_string ("egg", s);
  }
}

egg_Uses Parse_egg_Uses (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Uses ();
  } else {
    return (egg_Uses)egg_parse_string ("Uses", s);
  }
}

List_String Parse_egg_Strings (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Strings ();
  } else {
    return (List_String)egg_parse_string ("Strings", s);
  }
}

List_egg_Declaration Parse_egg_Declarations (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Declarations ();
  } else {
    return (List_egg_Declaration)egg_parse_string ("Declarations", s);
  }
}

egg_Declaration Parse_egg_Declaration (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Declaration ();
  } else {
    return (egg_Declaration)egg_parse_string ("Declaration", s);
  }
}

egg_Expression Parse_egg_Expression (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Expression ();
  } else {
    return (egg_Expression)egg_parse_string ("Expression", s);
  }
}

List_egg_Expression Parse_egg_Params (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Params ();
  } else {
    return (List_egg_Expression)egg_parse_string ("Params", s);
  }
}

List_egg_Statement Parse_egg_Statements (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Statements ();
  } else {
    return (List_egg_Statement)egg_parse_string ("Statements", s);
  }
}

egg_Statement Parse_egg_Statement (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Statement ();
  } else {
    return (egg_Statement)egg_parse_string ("Statement", s);
  }
}

egg_MessageKind Parse_egg_MessageKind (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_MessageKind ();
  } else {
    return (egg_MessageKind)egg_parse_string ("MessageKind", s);
  }
}

egg_Statement Parse_egg_Message (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Message ();
  } else {
    return (egg_Statement)egg_parse_string ("Message", s);
  }
}

List_egg_SubMessage Parse_egg_SubMessages (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_SubMessages ();
  } else {
    return (List_egg_SubMessage)egg_parse_string ("SubMessages", s);
  }
}

egg_SubMessage Parse_egg_SubMessage (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_SubMessage ();
  } else {
    return (egg_SubMessage)egg_parse_string ("SubMessage", s);
  }
}

egg_Statement Parse_egg_Group (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_Group ();
  } else {
    return (egg_Statement)egg_parse_string ("Group", s);
  }
}

List_egg_Statement Parse_egg_OPTMORE_Group (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_OPTMORE_Group ();
  } else {
    return (List_egg_Statement)egg_parse_string ("OPTMORE_Group", s);
  }
}

List_String Parse_egg_ALT_Stringsym_SEP_commasym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_ALT_Stringsym_SEP_commasym ();
  } else {
    return (List_String)egg_parse_string ("ALT_Stringsym_SEP_commasym", s);
  }
}

List_egg_Declaration Parse_egg_OPTMORE_Declaration (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_OPTMORE_Declaration ();
  } else {
    return (List_egg_Declaration)egg_parse_string ("OPTMORE_Declaration", s);
  }
}

List_egg_Expression Parse_egg_MORE_Expression (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_MORE_Expression ();
  } else {
    return (List_egg_Expression)egg_parse_string ("MORE_Expression", s);
  }
}

List_egg_Expression Parse_egg_ALT_Expression_SEP_commasym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_ALT_Expression_SEP_commasym ();
  } else {
    return (List_egg_Expression)egg_parse_string ("ALT_Expression_SEP_commasym", s);
  }
}

List_egg_Statement Parse_egg_OPTMORE_Statement (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_OPTMORE_Statement ();
  } else {
    return (List_egg_Statement)egg_parse_string ("OPTMORE_Statement", s);
  }
}

List_egg_SubMessage Parse_egg_ALT_SubMessage_SEP_commasym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (egg_use_lalr) {
    egg__switch_to_buffer (egg__scan_string (s));
    return Parse_state_egg_ALT_SubMessage_SEP_commasym ();
  } else {
    return (List_egg_SubMessage)egg_parse_string ("ALT_SubMessage_SEP_commasym", s);
  }
}

