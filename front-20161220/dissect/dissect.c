#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void __cyg_profile_func_enter (void *func_address, void *call_site)
     __attribute__ ((no_instrument_function));

void __cyg_profile_func_exit (void *func_address, void *call_site)
     __attribute__ ((no_instrument_function));
                                
void dissect_initialize (void)
     __attribute__ ((no_instrument_function, constructor));

void dissect_finish (void)
     __attribute__ ((no_instrument_function, destructor));
     
static void write_int(int val)
     __attribute__ ((no_instrument_function, destructor));
static void write_long_long(long long val)
     __attribute__ ((no_instrument_function, destructor));
static void write_char(int val)
     __attribute__ ((no_instrument_function, destructor));

inline unsigned long long int clock_ticks (void)
     __attribute__ ((no_instrument_function, destructor));
     
static void  initialize_hooks (void);
static void *malloc_hook (size_t, const void *);
static void *realloc_hook (void *, size_t, const void *);
static void  free_hook (void*, const void *);

static void *(*old_malloc_hook) (size_t, const void *);
static void *(*old_realloc_hook) (void *, size_t, const void *);
static void  (*old_free_hook) (void*, const void *);
static FILE *fs;     

static unsigned long long int start_time=0;

static void
fail (void)
{
  perror ("libdissect");
  exit(1);
}
     
inline unsigned long long int
clock_ticks (void)
{
  unsigned long long int x;
  __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
  return x - start_time;
}

static int
have_pipe (void)
{
  int result;
  errno = 0;
  fcntl(3, F_GETFL);
  result = (errno!=EBADF);
  errno = 0;
  return result;
}

void
dissect_initialize (void)
{
  extern char *program_invocation_name;
  static char buffer[1024*1024];
  char path[PATH_MAX];
  
  errno = 0;

  if (have_pipe ()) {
    fs = fdopen (3,"w");
    errno = 0;
    if(fs) fprintf (stderr, "libdissect: logging to pipe.\n");
  }
  if (!fs) {
    sprintf (path,"dissect%d.log",getpid());
    fs = fopen64 (path,"w");
    if (errno) fail();
    fprintf (stderr, "libdissect: logging to %s.\n", path);
  }
  
  setvbuf (fs, buffer, _IOFBF, sizeof(buffer));
  if (errno) fail();
  
  realpath (program_invocation_name, path);
  fprintf (fs, "%s\n", path);
  initialize_hooks ();
  start_time = clock_ticks ();
}

void
dissect_finish (void)
{
  FILE *cfs = fs;
  fs = NULL;
  fclose (cfs);
}
     
static void
save_hooks (void)
{
  old_malloc_hook = __malloc_hook;
  old_realloc_hook = __realloc_hook;
  old_free_hook = __free_hook;
}

static void
restore_hooks (void)
{
  __malloc_hook = old_malloc_hook;
  __realloc_hook = old_realloc_hook;
  __free_hook = old_free_hook;
}

static void
install_hooks (void)
{
  __malloc_hook = malloc_hook;
  __realloc_hook = realloc_hook;
  __free_hook = free_hook;
}

static void
initialize_hooks (void)
{
  save_hooks ();
  install_hooks ();
}

static void
write_int(int val)
{
  if (fs) fwrite (&val, sizeof(int), 1, fs);
}

static void
write_long_long(long long val)
{
  if (fs) fwrite (&val, sizeof(long long), 1, fs);
}

static void
write_char(int val)
{
  if (fs) fwrite (&val, sizeof(char), 1, fs);
}

static void *
malloc_hook (size_t size, const void *caller)
{
  void *result;

  caller = caller;
  restore_hooks ();
  result = malloc (size);
  
  write_char ('M');
  write_int ((int)result);
  write_int (size);
  
  initialize_hooks ();
  return result;
}

static void *
realloc_hook (void *ptr, size_t size, const void *caller)
{
  void *result;

  caller = caller;
  restore_hooks ();

  write_char ('F');
  write_int ((int)ptr);
  
  result = realloc (ptr, size);
  
  write_char ('M');
  write_int ((int)result);
  write_int (size);
  
  initialize_hooks ();
  return result;
}
     
static void
free_hook (void *ptr, const void *caller)
{
  caller = caller;
  restore_hooks ();
  free (ptr);
  
  write_char ('F');
  write_int ((int)ptr);
  
  initialize_hooks ();
}

void
__cyg_profile_func_enter (void *func_address, void __attribute__ ((unused)) *call_site)
{
  write_char ('E');
  write_int ((int)func_address);
  write_long_long (clock_ticks ());
}

void
__cyg_profile_func_exit (void *func_address, void __attribute__ ((unused)) *call_site)
{
  write_char ('X');
  write_int ((int)func_address);
  write_long_long (clock_ticks ());
}

