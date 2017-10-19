#ifndef _dissect_stack_h
#define _dissect_stack_h

#include <stdarg.h>

#include "graph.h"

node_t *stack_top (void);
void stack_push (node_t *nd);
node_t *stack_pop (void);
void stack_walk (void visit(node_t*,va_list), ...);

#endif/*  _dissect_stack_h */
