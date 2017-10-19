#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "parse_support.h"
#include "Diagrams_parse.h"
#include "Diagrams_lalr.h"

extern struct yy_buffer_state *Diagrams__scan_string (char *);
extern void Diagrams__switch_to_buffer (struct yy_buffer_state *);
extern int Diagrams_parse (void);

Bool Diagrams_use_lalr = FALSE;

static void Diagrams_parse_nt (char *nt, char *s)
{ char *t = Front_StrAllocf("%s_%s %s", "%", nt, s);
  Diagrams__switch_to_buffer (Diagrams__scan_string (t));
  Diagrams_parse();
}

static void *the_node;
void Diagrams_multi_action (void* n)
{ the_node = n; }

static void *Diagrams_parse_string (char *nt, char *s)
{ Diagrams_parse_nt (nt, s);
  assert (first_sub_tree==NULL);
  return the_node;
}

Diagrams_Diagrams Parse_Diagrams_Diagrams (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Diagrams_use_lalr) {
    Diagrams__switch_to_buffer (Diagrams__scan_string (s));
    return Parse_state_Diagrams_Diagrams ();
  } else {
    return (Diagrams_Diagrams)Diagrams_parse_string ("Diagrams", s);
  }
}

Diagrams_Direction Parse_Diagrams_Direction (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Diagrams_use_lalr) {
    Diagrams__switch_to_buffer (Diagrams__scan_string (s));
    return Parse_state_Diagrams_Direction ();
  } else {
    return (Diagrams_Direction)Diagrams_parse_string ("Direction", s);
  }
}

Diagrams_Picture Parse_Diagrams_Picture (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Diagrams_use_lalr) {
    Diagrams__switch_to_buffer (Diagrams__scan_string (s));
    return Parse_state_Diagrams_Picture ();
  } else {
    return (Diagrams_Picture)Diagrams_parse_string ("Picture", s);
  }
}

List_Diagrams_Picture Parse_Diagrams_OPTMORE_Picture (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Diagrams_use_lalr) {
    Diagrams__switch_to_buffer (Diagrams__scan_string (s));
    return Parse_state_Diagrams_OPTMORE_Picture ();
  } else {
    return (List_Diagrams_Picture)Diagrams_parse_string ("OPTMORE_Picture", s);
  }
}

List_Diagrams_Picture Parse_Diagrams_MORE_Picture (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Diagrams_use_lalr) {
    Diagrams__switch_to_buffer (Diagrams__scan_string (s));
    return Parse_state_Diagrams_MORE_Picture ();
  } else {
    return (List_Diagrams_Picture)Diagrams_parse_string ("MORE_Picture", s);
  }
}

