#include <stdio.h>

#include "draw.h"
#include "graph.h"
#include "readlog.h"

int omit_unconnected_nodes = 0;
int lost_lower_boundary = -1;
int lost_contribution_factor = 0;

double dur_lower_boundary = 0.0;
int dur_contribution_factor = 0;

static unsigned long long
compute_self_duration (node_t *nd)
{
  edge_t *es;
  unsigned long long duration = nd->duration;
  
  for (es = nd->succs; es; es = es->tail) {
    duration -= es->to->duration;
  }
  if (duration < nd->duration) return duration;
  /* overflow */
  return 0;
}

static int
edge_contributes (node_t *from, node_t *to)
{
  int from_lost = node_lost_mem (from);
  int to_lost   = node_lost_mem (to);
  double from_dur = (100.0 * from->duration) / total_duration;
  double to_dur   = (100.0 * to->duration) / total_duration;
  
  if (lost_contribution_factor && !no_memory_analysis) {
    if (to_lost * lost_contribution_factor < from_lost) return 0;
  }  
  if (dur_contribution_factor) {
    if (to_dur * dur_contribution_factor < from_dur) return 0;
  }
  return 1;
}

static void
analyse_node (node_t *nd)
{
  edge_t *es;
  int lost;

  if (nd->visited) return;
  nd->visited = 1;
  if (nd->count==0) return;
  
  if ((100.0 * nd->duration) / total_duration < dur_lower_boundary) return;
  if (!no_memory_analysis) {
    lost = node_lost_mem (nd);
    if (lost < lost_lower_boundary) return;
  }
  nd->draw_me = 1;
  
  for (es = nd->succs; es; es = es->tail) {
    if (edge_contributes (nd, es->to)) {
      es->draw_me = 1;
    }
    if (es->draw_me || !omit_unconnected_nodes) {
      es->to->draw_me = 1;
      analyse_node (es->to);
    }
  }
}

static void
analyse_graph (void)
{
  node_t *ns;
  
  for (ns = graph_nodes; ns; ns = ns->tail) {
    if (ns->is_entry) analyse_node (ns);
  }  
}

void
print_bytes (FILE *fs, unsigned n)
{
  double num = n;
  char *units[]={"b","kb","Mb","Gb","Tb"};
  int unit=0;

  while (num>1024) {
    num/=1024;
    unit++;
  }
  fprintf (fs,"%3.1f%s",num,units[unit]);
}

void
print_dot (FILE *fs, char *program)
{
  node_t *ns;
  edge_t *es;

  analyse_graph ();
  
  fprintf (fs, "digraph G {\n");
  fprintf (fs, "  label=\"%s\"\n", program);
  for (ns = graph_nodes; ns; ns = ns->tail) {
    int lost;
    if (ns->draw_me==0) continue;
    
    lost = node_lost_mem (ns);
    if (ns->name) {
      fprintf (fs, "  %u [label=\"%s", ns->id, ns->name);
      if (lost) {
        fprintf (fs, "\\nlost:");
        print_bytes (fs, lost);
      }
      fprintf (fs, "\\n%3.1f%%",
               (100.0*ns->duration)/total_duration);
      fprintf (fs, ", %3.1f%%",
               (100.0*compute_self_duration(ns))/total_duration);
      fprintf (fs, "\"]\n");
    }
    for (es = ns->succs; es; es = es->tail) {
      if (es->draw_me==0) continue;
      fprintf (fs, "  %u -> %u [label=\"%d\"]\n",
               ns->id, es->to->id, es->count);
    }
  }
  fprintf (fs, "}\n");
}
