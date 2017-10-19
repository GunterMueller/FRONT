#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "front/parse_support.h"
#include "front/mem.h"
#include "Pictures_parse.h"
#include "Pictures_lalr.h"

extern struct yy_buffer_state *Pictures__scan_string (char *);
extern struct yy_buffer_state *Pictures__scan_buffer (char *, size_t);
extern struct yy_buffer_state *Pictures__create_buffer (FILE *, int);
extern void Pictures__switch_to_buffer (struct yy_buffer_state *);
extern void Pictures_push_buffer_state (struct yy_buffer_state *);
extern void Pictures__delete_buffer (struct yy_buffer_state *);
extern int Pictures_parse (void);

Bool Pictures_use_lalr = FALSE;
extern int Pictures_state_stack_depth;
static void Pictures_parse_nt (char *nt, char *s)
{ char *t = (char*)fe_malloc(1+strlen(nt)+strlen(s)+3);
  struct yy_buffer_state *buf;  sprintf(t, "%s_%s %s", "%", nt, s);
  buf = Pictures__scan_string (t);  Pictures__switch_to_buffer (buf);
  Pictures_parse();
  Pictures__delete_buffer(buf);
}

static void *the_node;
void Pictures_multi_action (void* n)
{ the_node = n; }

static void *Pictures_parse_string (char *nt, char *s)
{
  the_node = NULL;
  Pictures_parse_nt (nt, s);
  assert (first_sub_tree==NULL);
  return the_node;
}

static struct yy_buffer_state *dummy_state (void)
{
  static struct yy_buffer_state *state = NULL;
  if (!state) state = Pictures__create_buffer (NULL,0);
  return state;
}

Pictures_Pictures Parse_Pictures_Pictures (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Pictures_use_lalr) {
    Pictures__switch_to_buffer (Pictures__scan_string (s));
    return Parse_state_Pictures_Pictures ();
  } else {
    return (Pictures_Pictures)Pictures_parse_string ("Pictures", s);
  }
}

Pictures_Direction Parse_Pictures_Direction (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Pictures_use_lalr) {
    Pictures__switch_to_buffer (Pictures__scan_string (s));
    return Parse_state_Pictures_Direction ();
  } else {
    return (Pictures_Direction)Pictures_parse_string ("Direction", s);
  }
}

Pictures_Picture Parse_Pictures_Picture (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Pictures_use_lalr) {
    Pictures__switch_to_buffer (Pictures__scan_string (s));
    return Parse_state_Pictures_Picture ();
  } else {
    return (Pictures_Picture)Pictures_parse_string ("Picture", s);
  }
}

List_Pictures_Picture Parse_Pictures_OPTMORE_Picture (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Pictures_use_lalr) {
    Pictures__switch_to_buffer (Pictures__scan_string (s));
    return Parse_state_Pictures_OPTMORE_Picture ();
  } else {
    return (List_Pictures_Picture)Pictures_parse_string ("OPTMORE_Picture", s);
  }
}

List_Pictures_Picture Parse_Pictures_MORE_Picture (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Pictures_use_lalr) {
    Pictures__switch_to_buffer (Pictures__scan_string (s));
    return Parse_state_Pictures_MORE_Picture ();
  } else {
    return (List_Pictures_Picture)Pictures_parse_string ("MORE_Picture", s);
  }
}

