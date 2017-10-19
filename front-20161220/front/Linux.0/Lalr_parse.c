#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "front/parse_support.h"
#include "front/mem.h"
#include "Lalr_parse.h"
#include "Lalr_lalr.h"

extern struct yy_buffer_state *Lalr__scan_string (char *);
extern struct yy_buffer_state *Lalr__scan_buffer (char *, size_t);
extern struct yy_buffer_state *Lalr__create_buffer (FILE *, int);
extern void Lalr__switch_to_buffer (struct yy_buffer_state *);
extern void Lalr_push_buffer_state (struct yy_buffer_state *);
extern void Lalr__delete_buffer (struct yy_buffer_state *);
extern int Lalr_parse (void);

Bool Lalr_use_lalr = FALSE;
extern int Lalr_state_stack_depth;
static void Lalr_parse_nt (char *nt, char *s)
{ char *t = (char*)fe_malloc(1+strlen(nt)+strlen(s)+3);
  struct yy_buffer_state *buf;  sprintf(t, "%s_%s %s", "%", nt, s);
  buf = Lalr__scan_string (t);  Lalr__switch_to_buffer (buf);
  Lalr_parse();
  Lalr__delete_buffer(buf);
}

static void *the_node;
void Lalr_multi_action (void* n)
{ the_node = n; }

static void *Lalr_parse_string (char *nt, char *s)
{
  the_node = NULL;
  Lalr_parse_nt (nt, s);
  assert (first_sub_tree==NULL);
  return the_node;
}

static struct yy_buffer_state *dummy_state (void)
{
  static struct yy_buffer_state *state = NULL;
  if (!state) state = Lalr__create_buffer (NULL,0);
  return state;
}

Lalr_Lalr Parse_Lalr_Lalr (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_Lalr ();
  } else {
    return (Lalr_Lalr)Lalr_parse_string ("Lalr", s);
  }
}

Lalr_Production Parse_Lalr_Production (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_Production ();
  } else {
    return (Lalr_Production)Lalr_parse_string ("Production", s);
  }
}

Lalr_LR_Symbols Parse_Lalr_ProdRhs (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_ProdRhs ();
  } else {
    return (Lalr_LR_Symbols)Lalr_parse_string ("ProdRhs", s);
  }
}

Lalr_LR_Symbol Parse_Lalr_LR_Symbol (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_LR_Symbol ();
  } else {
    return (Lalr_LR_Symbol)Lalr_parse_string ("LR_Symbol", s);
  }
}

Lalr_LR_Symbols Parse_Lalr_LR_Symbols (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_LR_Symbols ();
  } else {
    return (Lalr_LR_Symbols)Lalr_parse_string ("LR_Symbols", s);
  }
}

Lalr_Emptiness Parse_Lalr_Emptiness (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_Emptiness ();
  } else {
    return (Lalr_Emptiness)Lalr_parse_string ("Emptiness", s);
  }
}

Lalr_LR_state Parse_Lalr_LR_state (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_LR_state ();
  } else {
    return (Lalr_LR_state)Lalr_parse_string ("LR_state", s);
  }
}

Lalr_Item Parse_Lalr_Item (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_Item ();
  } else {
    return (Lalr_Item)Lalr_parse_string ("Item", s);
  }
}

List_Ident Parse_Lalr_TermSet (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_TermSet ();
  } else {
    return (List_Ident)Lalr_parse_string ("TermSet", s);
  }
}

Lalr_Transition Parse_Lalr_Transition (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_Transition ();
  } else {
    return (Lalr_Transition)Lalr_parse_string ("Transition", s);
  }
}

List_Lalr_Production Parse_Lalr_OPTMORE_Production (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_OPTMORE_Production ();
  } else {
    return (List_Lalr_Production)Lalr_parse_string ("OPTMORE_Production", s);
  }
}

List_Lalr_LR_state Parse_Lalr_OPTMORE_LR_state (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_OPTMORE_LR_state ();
  } else {
    return (List_Lalr_LR_state)Lalr_parse_string ("OPTMORE_LR_state", s);
  }
}

List_Lalr_Item Parse_Lalr_MORE_Item (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_MORE_Item ();
  } else {
    return (List_Lalr_Item)Lalr_parse_string ("MORE_Item", s);
  }
}

List_Lalr_Transition Parse_Lalr_OPTMORE_Transition (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_OPTMORE_Transition ();
  } else {
    return (List_Lalr_Transition)Lalr_parse_string ("OPTMORE_Transition", s);
  }
}

List_Lalr_LR_Symbol Parse_Lalr_OPTMORE_LR_Symbol (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_OPTMORE_LR_Symbol ();
  } else {
    return (List_Lalr_LR_Symbol)Lalr_parse_string ("OPTMORE_LR_Symbol", s);
  }
}

List_Ident Parse_Lalr_MORE_Identsym_spacesym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Lalr_use_lalr) {
    Lalr__switch_to_buffer (Lalr__scan_string (s));
    return Parse_state_Lalr_MORE_Identsym_spacesym ();
  } else {
    return (List_Ident)Lalr_parse_string ("MORE_Identsym_spacesym", s);
  }
}

