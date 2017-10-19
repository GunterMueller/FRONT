#ifndef _Diagrams_parse_h
#define _Diagrams_parse_h

#include "Diagrams.h"

extern Bool Diagrams_use_lalr;

extern void Diagrams_multi_action (void*);

extern Diagrams_Diagrams Parse_Diagrams_Diagrams (char *s, int n, ...);
extern Diagrams_Direction Parse_Diagrams_Direction (char *s, int n, ...);
extern Diagrams_Picture Parse_Diagrams_Picture (char *s, int n, ...);
extern List_Diagrams_Picture Parse_Diagrams_OPTMORE_Picture (char *s, int n, ...);
extern List_Diagrams_Picture Parse_Diagrams_MORE_Picture (char *s, int n, ...);
#endif /* _Diagrams_parse_h*/
