#ifndef _Types_parse_h
#define _Types_parse_h

#include "Types.h"

extern void Types_multi_action (void*);

struct yy_buffer_state;

extern Bool Types_use_lalr;
extern int Types_state_stack_depth;

extern Types_Types Parse_Types_Types (char *s, int n, ...);
extern Types_includes2 Parse_Types_includes2 (char *s, int n, ...);
extern Types_EnumType Parse_Types_EnumType (char *s, int n, ...);
extern List_Types_TypeName Parse_Types_Enums (char *s, int n, ...);
extern Types_BindType Parse_Types_BindType (char *s, int n, ...);
extern Types_PointerType Parse_Types_PointerType (char *s, int n, ...);
extern Types_subtypedef Parse_Types_subtypedef (char *s, int n, ...);
extern Types_StructType Parse_Types_StructType (char *s, int n, ...);
extern Types_struct_type Parse_Types_struct_type (char *s, int n, ...);
extern List_Types_struct_type Parse_Types_sub_union (char *s, int n, ...);
extern Types_macro Parse_Types_macro (char *s, int n, ...);
extern Types_field Parse_Types_field (char *s, int n, ...);
extern Types_TypeName Parse_Types_TypeName (char *s, int n, ...);
extern Types_CreateFunction Parse_Types_CreateFunction (char *s, int n, ...);
extern List_Types_TypeName Parse_Types_TypeNames (char *s, int n, ...);
extern List_Types_EnumType Parse_Types_OPTMORE_EnumType (char *s, int n, ...);
extern List_Types_PointerType Parse_Types_OPTMORE_PointerType (char *s, int n, ...);
extern List_Types_subtypedef Parse_Types_OPTMORE_subtypedef (char *s, int n, ...);
extern List_Types_BindType Parse_Types_OPTMORE_BindType (char *s, int n, ...);
extern List_Types_StructType Parse_Types_OPTMORE_StructType (char *s, int n, ...);
extern List_Ident Parse_Types_OPTMORE_hashincludespacebackslashdoublequotesym_Identsym_dothbackslashdoublequotesym (char *s, int n, ...);
extern List_Types_TypeName Parse_Types_ALT_TypeName_SEP_commasym_NL (char *s, int n, ...);
extern List_Types_macro Parse_Types_OPTMORE_macro (char *s, int n, ...);
extern List_Types_CreateFunction Parse_Types_OPTMORE_CreateFunction (char *s, int n, ...);
extern List_Types_field Parse_Types_OPTMORE_field (char *s, int n, ...);
extern List_Types_struct_type Parse_Types_OPTMORE_struct_type (char *s, int n, ...);
extern List_Ident Parse_Types_OPTMORE_dotsubdotsym_Identsym (char *s, int n, ...);
extern List_Types_TypeName Parse_Types_ALT_TypeName_SEP__sym (char *s, int n, ...);
#endif /* _Types_parse_h*/
