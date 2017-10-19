#ifndef _dissect_draw_h
#define _dissect_draw_h

#include <stdio.h>

extern int omit_unconnected_nodes;

extern int lost_lower_boundary;
extern int lost_contribution_factor;

extern double dur_lower_boundary;
extern int dur_contribution_factor;

void print_dot (FILE *fs, char *program);

#endif /* _dissect_draw_h */
