#include <stdio.h>
#include <stdlib.h>
#include <front/hash.h>

#include "alloc.h"
#include "graph.h"

static hash_t node_table;
node_t *graph_nodes = NULL;

static unsigned mem_used;

static int
has_key (node_t *me, unsigned id)
{
  return me->id==id;
}

static unsigned
make_key (unsigned id)
{
  return id;
}

node_t *
node_new (unsigned id, node_t *pred)
{
  node_t *me = malloc (sizeof(*me));
  mem_used += sizeof(*me);
  
  if (pred) me->tail = pred->tail;
  else      me->tail = graph_nodes;
  me->id = id;
  me->succs = NULL;
  me->name = NULL;
  me->count = 0;
  me->is_entry = 0;
  me->draw_me = 0;
  me->visited = 0;
  me->allocations = NULL;
  me->duration = 0;
  if (pred) pred->tail = me;
  else      graph_nodes = me;

  if (!node_table) {
    node_table = Front_Make_hash_table ((void*)make_key, (void*)has_key);
  }
  Front_Add_in_hash_table (node_table, (void*)id, me);
  
  return me;
}

edge_t *
edge_new (node_t *from, node_t *to)
{
  edge_t *me = NULL;

  if (!from || !to) return NULL;
  
  for (me = from->succs; me; me = me->tail) {
    if (me->to == to) break;
  }
  if (!me) {
    me = malloc (sizeof(*me));
    mem_used += sizeof(*me);
    me->tail = from->succs;
    me->to   = to;
    me->count = 0;
    me->draw_me = 0;
    from->succs = me;
  }
  me->count ++;
  return me;
}

node_t *
node_find (unsigned id)
{
  if (!node_table) return NULL;
  return Front_Find_in_hash_table (node_table, (void*)id);
}

node_t *
node_get (unsigned id)
{
  node_t *nd = node_find (id);

  if (nd) return nd;
  return node_new (id, NULL);
}

void
node_add_alloc (node_t *me, alloc_t *alloc)
{
  if (alloc_list_last(me->allocations) != alloc) {
    me->allocations = alloc_list_prepend (me->allocations, alloc);
  }
}

unsigned
node_lost_mem (node_t *me)
{
  return alloc_list_lost_mem (me->allocations);
}

int
num_nodes (void)
{
  node_t *ns;
  int i=0;
  for (ns = graph_nodes; ns; ns = ns->tail) {
    i++;
  }
  return i;
}

void
graph_sweep (void)
{
  node_t *ns;

  for (ns = graph_nodes; ns; ns = ns->tail) {
    ns->allocations = alloc_list_sweep (ns->allocations);
  }
  allocations_sweep ();
}

void
graph_print_mem_used (void)
{
  fprintf (stderr,"graph: %u bytes\n", mem_used);
}
