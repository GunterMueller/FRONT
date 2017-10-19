#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alloc.h"
#include "binary.h"
#include "graph.h"
#include "stack.h"

int print_log = 0;
int no_memory_analysis = 0;
unsigned long long total_duration;

static int
read_char (FILE *fs)
{
  int data=0;
  fread (&data,1,1,fs);
  return data;
}

static int
read_int (FILE *fs)
{
  int data=0;
  fread (&data,sizeof(int),1,fs);
  return data;
}

static long long
read_long_long (FILE *fs)
{
  long long data=0;
  fread (&data,sizeof(long long),1,fs);
  return data;
}

static void
associate_node_alloc (node_t *nd, va_list args)
{
  node_add_alloc (nd, va_arg (args, alloc_t*));
}

static void
read_malloc (FILE *fs)
{
  unsigned ptr  = read_int (fs);
  unsigned size = read_int (fs);

  if (feof (fs)) return;
  
  if (!no_memory_analysis) {
    stack_walk (associate_node_alloc, alloc_add (ptr, size));
  }
  if (print_log) printf ("M %x %u\n", ptr, size);
}

static void
read_free (FILE *fs)
{
  unsigned ptr = read_int (fs);

  if (feof (fs)) return;
  if (!ptr) return;
  if (!no_memory_analysis) alloc_rm (ptr);
  if (print_log) printf ("F %x\n", ptr);
}

static void
read_entry (FILE *fs)
{
  unsigned id = read_int (fs);
  unsigned long long time = read_long_long (fs);
  node_t *nd;

  if (feof (fs)) return;
  nd = node_get (id);
  nd->count ++;
  nd->is_entry = (stack_top()==NULL);
  nd->duration -= time;
  stack_push (nd);
  if (print_log) printf ("E %x %lld (%s)\n", id, time, nd->name);
  total_duration = time;
}

static void
read_exit (FILE *fs)
{
  unsigned id = read_int (fs);
  unsigned long long time = read_long_long (fs);
  node_t *nd;
  
  if (feof (fs)) return;
  nd = stack_pop ();
  assert (id==nd->id);
  nd->duration += time;
  if (print_log) printf ("X %x %lld (%s)\n", id, time, nd->name);
  total_duration = time;
}

static void
exit_function_stack (void)
{
  node_t *nd;

  while ( (nd = stack_pop ()) ) {
    nd->duration += total_duration;
    if (print_log) printf ("X %x %lld (%s)\n", nd->id, total_duration, nd->name);
  }
}

static int
out_of_memory(void)
{
  int result=0;
  void *p;
  errno = 0;
  p = malloc (1024*100);
  if (errno==ENOMEM) {
    graph_sweep ();
    errno = 0;
    p = malloc (1024*100);
    result = (errno==ENOMEM);
  }
  free (p);
  errno = 0;
  return result;
}

static off64_t
file_size (FILE *fs)
{
  off64_t cp, res;
  
  errno = 0;
  cp = ftello64 (fs);
  if (errno==EBADF || cp==(off64_t)-1) {
    /* not a seekable stream */
    errno=0;
    return 0;
  }
  fseeko64 (fs, 0, SEEK_END);
  res = ftello64 (fs);
  fseeko64 (fs, cp, SEEK_SET);
  if (errno) {
    perror ("dissect");
    exit(1);
  }
  return res;
}

static void
show_progress (FILE *fs, off64_t size)
{
  static double last=0;
  off64_t cp;
  double perc;

  if (!size) return;
  
  cp = ftello64(fs);
  perc = ((double)((10000*cp)/size))/100.0;

  if (cp==size) {
    fprintf (stderr, "done\n");
    return;
  }
  if (perc>last+0.1) {
    fprintf (stderr, "read %3.1f%%\r", perc);
    fflush (stderr);
    last = perc;
  }
}

void
read_entries (FILE *fs, off64_t size)
{
  node_t *ns;
  
  errno = 0;
  while (1) {
    int entry = read_char (fs);
    if (feof (fs)) break;
    show_progress (fs, size);
    if (out_of_memory ()) {
      fprintf (stderr, "dissect: I need more memory, using truncated log file.\n");
      break;
    }

    switch (entry) {
    case 'M': read_malloc (fs); break;
    case 'F': read_free (fs); break;
    case 'E': read_entry (fs); break;
    case 'X': read_exit (fs); break;
    default:
      fprintf (stderr, "dissect: corrupt log file\n");
      exit(1);
    }
    if (errno) {
      perror ("dissect");
      exit(1);
    }
  }
  exit_function_stack ();
  
  for (ns = graph_nodes; ns; ns = ns->tail) {
    if (!ns->count) continue;
    ns->duration /= ns->count;
  }
  
  show_progress (fs, size);
}

char *
read_log (FILE *fs)
{
  char buffer[1024];
  char *program;
  off64_t size;
  
  size = file_size (fs);
  fgets (buffer, 1024, fs);
  program = strdup (strtok(buffer,"\n"));

  read_entries (fs, size);
  
  fclose (fs);

  if (!scan_binary (program)) {
    fprintf (stderr, "dissect: error reading binary \"%s\"\n", program);
    exit (1);
  }
  
  return program;
}

