#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <front/flags.h>

#include "draw.h"
#include "graph.h"
#include "input.h"
#include "readlog.h"
#include "stack.h"

static char *outfile = NULL;
static char *program;
static int print_cflags = 0;
static int print_libs = 0;
static int list_all = 0;
static int stats = 0;

static char **command_line = NULL;

static int set_output(int argc, char *argv[]);
static int set_lost_min(int argc, char *argv[]);
static int set_lost_contribution(int argc, char *argv[]);
static int set_dur_min(int argc, char *argv[]);
static int set_dur_contribution(int argc, char *argv[]);
static int set_run_command(int argc, char *argv[]);

fe_cli_flag dissect_flags[] = {
  { "-h", NULL,	      fe_help_flag,          DFLT_NAME,   { "display help message" } },
  { "-o", NULL,	      set_output,            "-o <file>", { "write output to <file>" } },
  { "-lmin", NULL, set_lost_min,             "-lmin <num>", { "don't draw nodes with lost bytes < <num>" } },
  { "-lcf", NULL,  set_lost_contribution,    "-lcf <num>", { "don't draw edges that contribute < <num> times to the lost bytes of the parent" } },
  { "-dmin", NULL, set_dur_min,              "-dmin <num>", { "don't draw nodes with duration < <num>" } },
  { "-dcf", NULL,  set_dur_contribution,     "-dcf <num>", { "don't draw edges that contribute < <num> times to the duration of the parent" } },
  { "-oun", &omit_unconnected_nodes, NULL,   DFLT_NAME,   { "don't draw nodes that have become unconnected due to a filter" } },
  { "-list", &list_all, NULL,                DFLT_NAME,   { "list all functions and their lost memory counts" } },
  { "-nma", &no_memory_analysis, NULL,       DFLT_NAME,   { "disable memory analysis" } },
  { "-print-log", &print_log, NULL,          DFLT_NAME,   { "print a readable form of the log file" } },
  { "-stats", &stats, NULL,                  DFLT_NAME,   { "print internal stats" } },
  { "-run", NULL, set_run_command,           "-run <command>",   { "fetch the log from the command" } },
  { "--cflags", &print_cflags, NULL,         DFLT_NAME,   { "print cflags required for using dissect" } },
  { "--libs", &print_libs, NULL,             DFLT_NAME,   { "print libs required for using dissect" } },
};
const int num_dissect_flags=(sizeof(dissect_flags) / sizeof(*dissect_flags));

/* ------------------------------------------------------------------------- */
static int
set_output(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf (stderr, "missing argument: -o\n");
    exit (1);
  }
  outfile = argv[1];
  return 1;  
}

/* ------------------------------------------------------------------------- */
static int
set_lost_min(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf (stderr, "missing argument: -lmin\n");
    exit (1);
  }
  lost_lower_boundary = atoi(argv[1]);
  return 1;  
}

/* ------------------------------------------------------------------------- */
static int
set_lost_contribution(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf (stderr, "missing argument: -lcf\n");
    exit (1);
  }
  lost_contribution_factor = atoi(argv[1]);
  return 1;  
}

/* ------------------------------------------------------------------------- */
static int
set_dur_min(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf (stderr, "missing argument: -dmin\n");
    exit (1);
  }
  dur_lower_boundary = atof(argv[1]);
  return 1;  
}

/* ------------------------------------------------------------------------- */
static int
set_dur_contribution(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf (stderr, "missing argument: -dcf\n");
    exit (1);
  }
  dur_contribution_factor = atoi(argv[1]);
  return 1;  
}

/* ------------------------------------------------------------------------- */
static int
set_run_command(int argc, char *argv[])
{
  command_line = argv+1;
  return argc;
}

/* ----------------------------------------------------------------------------
 * Parse the command line
 */
static char *
parse_options (int argc, char *argv[])
{
  fe_register_flags (num_dissect_flags, dissect_flags);
  argc = fe_parse_flags (argc, argv);
  if (argc==1) return NULL;
  return argv[1];
}

static void
list_functions(FILE *fs)
{
  node_t *ns;
  
  for (ns = graph_nodes; ns; ns = ns->tail) {
    if (ns->count && ns->is_entry) {
      fprintf (fs, "%s %d %lld %3.1f%% (entry point)\n", ns->name, node_lost_mem (ns), ns->duration, (100.0*ns->duration)/total_duration);
    } else if (ns->count) {
      fprintf (fs, "%s %d %lld %3.1f%%\n", ns->name, node_lost_mem (ns), ns->duration, (100.0*ns->duration)/total_duration);
    } else {
      fprintf (fs, "%s unused\n", ns->name);
    }
  }
}

/* Dissect the trace file */
int
main(int argc, char **argv)
{
  FILE *fs = stdout;
  char *infile;

  errno = 0;
  infile = parse_options (argc, argv);

  if (infile && command_line) {
    fprintf (stderr,"error: both command and input file specified.\n");
    exit (1);
  }
  if (print_cflags || print_libs) {
    if (print_cflags) printf (" -finstrument-functions");
    if (print_libs)   printf (" -ldissect");
    printf ("\n");
    if (!infile) return 0;
  }
  if (infile) {
    program = read_log (open_log (infile));
  } else if (command_line) {
    program = read_log (pipe_log (command_line));
  }
  if (stats) {
    fprintf (stderr, "%d allocations, %d called functions\n", num_allocations(), num_nodes());
    alloc_print_mem_used ();
    graph_print_mem_used ();
  }
  
  if (outfile) {
    fs = fopen (outfile,"w");
    if (!fs) {
      perror ("dissect");
      exit(1);
    }
  }
  if (list_all) list_functions (fs);
  else print_dot (fs, program);
  return 0;
}
