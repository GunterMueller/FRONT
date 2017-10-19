#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "front/parse_support.h"
#include "front/mem.h"
#include "Types_parse.h"
#include "Types_lalr.h"

extern struct yy_buffer_state *Types__scan_string (char *);
extern struct yy_buffer_state *Types__scan_buffer (char *, size_t);
extern struct yy_buffer_state *Types__create_buffer (FILE *, int);
extern void Types__switch_to_buffer (struct yy_buffer_state *);
extern void Types_push_buffer_state (struct yy_buffer_state *);
extern void Types__delete_buffer (struct yy_buffer_state *);
extern int Types_parse (void);

Bool Types_use_lalr = FALSE;
extern int Types_state_stack_depth;
static void Types_parse_nt (char *nt, char *s)
{ char *t = (char*)fe_malloc(1+strlen(nt)+strlen(s)+3);
  struct yy_buffer_state *buf;  sprintf(t, "%s_%s %s", "%", nt, s);
  buf = Types__scan_string (t);  Types__switch_to_buffer (buf);
  Types_parse();
  Types__delete_buffer(buf);
}

static void *the_node;
void Types_multi_action (void* n)
{ the_node = n; }

static void *Types_parse_string (char *nt, char *s)
{
  the_node = NULL;
  Types_parse_nt (nt, s);
  assert (first_sub_tree==NULL);
  return the_node;
}

static struct yy_buffer_state *dummy_state (void)
{
  static struct yy_buffer_state *state = NULL;
  if (!state) state = Types__create_buffer (NULL,0);
  return state;
}

Types_Types Parse_Types_Types (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_Types ();
  } else {
    return (Types_Types)Types_parse_string ("Types", s);
  }
}

Types_includes2 Parse_Types_includes2 (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_includes2 ();
  } else {
    return (Types_includes2)Types_parse_string ("includes2", s);
  }
}

Types_EnumType Parse_Types_EnumType (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_EnumType ();
  } else {
    return (Types_EnumType)Types_parse_string ("EnumType", s);
  }
}

List_Types_TypeName Parse_Types_Enums (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_Enums ();
  } else {
    return (List_Types_TypeName)Types_parse_string ("Enums", s);
  }
}

Types_BindType Parse_Types_BindType (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_BindType ();
  } else {
    return (Types_BindType)Types_parse_string ("BindType", s);
  }
}

Types_PointerType Parse_Types_PointerType (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_PointerType ();
  } else {
    return (Types_PointerType)Types_parse_string ("PointerType", s);
  }
}

Types_subtypedef Parse_Types_subtypedef (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_subtypedef ();
  } else {
    return (Types_subtypedef)Types_parse_string ("subtypedef", s);
  }
}

Types_StructType Parse_Types_StructType (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_StructType ();
  } else {
    return (Types_StructType)Types_parse_string ("StructType", s);
  }
}

Types_struct_type Parse_Types_struct_type (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_struct_type ();
  } else {
    return (Types_struct_type)Types_parse_string ("struct_type", s);
  }
}

List_Types_struct_type Parse_Types_sub_union (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_sub_union ();
  } else {
    return (List_Types_struct_type)Types_parse_string ("sub_union", s);
  }
}

Types_macro Parse_Types_macro (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_macro ();
  } else {
    return (Types_macro)Types_parse_string ("macro", s);
  }
}

Types_field Parse_Types_field (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_field ();
  } else {
    return (Types_field)Types_parse_string ("field", s);
  }
}

Types_TypeName Parse_Types_TypeName (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_TypeName ();
  } else {
    return (Types_TypeName)Types_parse_string ("TypeName", s);
  }
}

Types_CreateFunction Parse_Types_CreateFunction (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_CreateFunction ();
  } else {
    return (Types_CreateFunction)Types_parse_string ("CreateFunction", s);
  }
}

List_Types_TypeName Parse_Types_TypeNames (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_TypeNames ();
  } else {
    return (List_Types_TypeName)Types_parse_string ("TypeNames", s);
  }
}

List_Types_EnumType Parse_Types_OPTMORE_EnumType (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_EnumType ();
  } else {
    return (List_Types_EnumType)Types_parse_string ("OPTMORE_EnumType", s);
  }
}

List_Types_PointerType Parse_Types_OPTMORE_PointerType (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_PointerType ();
  } else {
    return (List_Types_PointerType)Types_parse_string ("OPTMORE_PointerType", s);
  }
}

List_Types_subtypedef Parse_Types_OPTMORE_subtypedef (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_subtypedef ();
  } else {
    return (List_Types_subtypedef)Types_parse_string ("OPTMORE_subtypedef", s);
  }
}

List_Types_BindType Parse_Types_OPTMORE_BindType (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_BindType ();
  } else {
    return (List_Types_BindType)Types_parse_string ("OPTMORE_BindType", s);
  }
}

List_Types_StructType Parse_Types_OPTMORE_StructType (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_StructType ();
  } else {
    return (List_Types_StructType)Types_parse_string ("OPTMORE_StructType", s);
  }
}

List_Ident Parse_Types_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym ();
  } else {
    return (List_Ident)Types_parse_string ("OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym", s);
  }
}

List_Types_TypeName Parse_Types_ALT_TypeName_SEP_commasym_NL (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_ALT_TypeName_SEP_commasym_NL ();
  } else {
    return (List_Types_TypeName)Types_parse_string ("ALT_TypeName_SEP_commasym_NL", s);
  }
}

List_Types_macro Parse_Types_OPTMORE_macro (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_macro ();
  } else {
    return (List_Types_macro)Types_parse_string ("OPTMORE_macro", s);
  }
}

List_Types_CreateFunction Parse_Types_OPTMORE_CreateFunction (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_CreateFunction ();
  } else {
    return (List_Types_CreateFunction)Types_parse_string ("OPTMORE_CreateFunction", s);
  }
}

List_Types_field Parse_Types_OPTMORE_field (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_field ();
  } else {
    return (List_Types_field)Types_parse_string ("OPTMORE_field", s);
  }
}

List_Types_struct_type Parse_Types_OPTMORE_struct_type (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_struct_type ();
  } else {
    return (List_Types_struct_type)Types_parse_string ("OPTMORE_struct_type", s);
  }
}

List_Ident Parse_Types_OPTMORE_dotsubdotsym_Identsym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_OPTMORE_dotsubdotsym_Identsym ();
  } else {
    return (List_Ident)Types_parse_string ("OPTMORE_dotsubdotsym_Identsym", s);
  }
}

List_Types_TypeName Parse_Types_ALT_TypeName_SEP__sym (char *s, int n, ...)
{ va_list p;
  va_start(p, n); Put_sub_trees (n, p); va_end(p);
  set_first_line (INT_MIN);
  if (Types_use_lalr) {
    Types__switch_to_buffer (Types__scan_string (s));
    return Parse_state_Types_ALT_TypeName_SEP__sym ();
  } else {
    return (List_Types_TypeName)Types_parse_string ("ALT_TypeName_SEP__sym", s);
  }
}

