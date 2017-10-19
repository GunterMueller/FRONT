#ifndef _Pictures_parse_h
#define _Pictures_parse_h

#include "Pictures.h"

extern void Pictures_multi_action (void*);

struct yy_buffer_state;

extern Bool Pictures_use_lalr;
extern int Pictures_state_stack_depth;

extern Pictures_Pictures Parse_Pictures_Pictures (char *s, int n, ...);
extern Pictures_Direction Parse_Pictures_Direction (char *s, int n, ...);
extern Pictures_Picture Parse_Pictures_Picture (char *s, int n, ...);
extern List_Pictures_Picture Parse_Pictures_OPTMORE_Picture (char *s, int n, ...);
extern List_Pictures_Picture Parse_Pictures_MORE_Picture (char *s, int n, ...);
#endif /* _Pictures_parse_h*/
