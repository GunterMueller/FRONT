#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"

typedef struct node_stack_s node_stack_t;

struct node_stack_s {
  node_stack_t *stack;
  node_t *node;
};

static node_stack_t *node_stack_top;

node_t *
stack_top (void)
{
  if (!node_stack_top) return NULL;
  return node_stack_top->node;
}

void
stack_push (node_t *nd)
{
  node_stack_t *me = malloc (sizeof (*me));

  me->stack = node_stack_top;
  me->node = nd;
  edge_new (stack_top(), nd);
  
  node_stack_top = me;
}

node_t *
stack_pop (void)
{
  node_t *nd;
  node_stack_t *ns;
  
  if (!node_stack_top) return NULL;
  nd = node_stack_top->node;
  ns = node_stack_top;
  node_stack_top = ns->stack;
  free (ns);
  return nd;
}

void
stack_walk (void visit(node_t*,va_list), ...)
{
  va_list args;
  node_stack_t *s;

  va_start (args, visit);
  for (s = node_stack_top; s; s = s->stack) {
    visit (s->node, args);
  }
  va_end (args);
}

void
stack_print (void)
{
  node_stack_t *s;
  
  for (s = node_stack_top; s; s = s->stack) {
    printf ("%x\n", s->node->id);
  }
}
