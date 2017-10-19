#ifndef _Lalr_parse_h
#define _Lalr_parse_h

#include "Lalr.h"

extern void Lalr_multi_action (void*);

struct yy_buffer_state;

extern Bool Lalr_use_lalr;
extern int Lalr_state_stack_depth;

extern Lalr_Lalr Parse_Lalr_Lalr (char *s, int n, ...);
extern Lalr_Production Parse_Lalr_Production (char *s, int n, ...);
extern Lalr_LR_Symbols Parse_Lalr_ProdRhs (char *s, int n, ...);
extern Lalr_LR_Symbol Parse_Lalr_LR_Symbol (char *s, int n, ...);
extern Lalr_LR_Symbols Parse_Lalr_LR_Symbols (char *s, int n, ...);
extern Lalr_Emptiness Parse_Lalr_Emptiness (char *s, int n, ...);
extern Lalr_LR_state Parse_Lalr_LR_state (char *s, int n, ...);
extern Lalr_Item Parse_Lalr_Item (char *s, int n, ...);
extern List_Ident Parse_Lalr_TermSet (char *s, int n, ...);
extern Lalr_Transition Parse_Lalr_Transition (char *s, int n, ...);
extern List_Lalr_Production Parse_Lalr_OPTMORE_Production (char *s, int n, ...);
extern List_Lalr_LR_state Parse_Lalr_OPTMORE_LR_state (char *s, int n, ...);
extern List_Lalr_Item Parse_Lalr_MORE_Item (char *s, int n, ...);
extern List_Lalr_Transition Parse_Lalr_OPTMORE_Transition (char *s, int n, ...);
extern List_Lalr_LR_Symbol Parse_Lalr_OPTMORE_LR_Symbol (char *s, int n, ...);
extern List_Ident Parse_Lalr_MORE_Identsym_spacesym (char *s, int n, ...);
#endif /* _Lalr_parse_h*/
