#ifndef _dissect_graph_h
#define _dissect_graph_h

typedef struct node_s node_t;
typedef struct edge_s edge_t;

#include "alloc.h"

extern node_t *graph_nodes;

struct node_s {
  node_t *tail;
  edge_t *succs;
  unsigned id;
  char *name;
  alloc_list_t *allocations;
  int count;
  int is_entry:1;
  int draw_me:1;
  int visited:1;
  unsigned long long duration;
};

struct edge_s {
  edge_t *tail;
  node_t *to;
  int count;
  int draw_me:1;
};

node_t *node_new (unsigned id, node_t *pred);
edge_t *edge_new (node_t *from, node_t *to);
node_t *node_find (unsigned id);
node_t *node_get (unsigned id);
void node_add_alloc (node_t *me, alloc_t *alloc);
unsigned node_lost_mem (node_t *me);

void graph_sweep (void);

int num_nodes (void);
void graph_print_mem_used (void);

#endif/*  _dissect_graph_h */
