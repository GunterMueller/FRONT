#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static void
syschk(void)
{
  if (errno)  {
    fprintf (stderr, "%d: ", getpid());
    perror ("dissect");
    exit(1);
  }
}

FILE *
open_log (char *filename)
{
  FILE *fs = fopen64 (filename,"r");
  if (!fs) {
    perror ("dissect");
    exit(1);
  }
  return fs;
}

static FILE *
parent (int readfd)
{
  FILE *fs;
  char id[8];
  
  fs = fdopen (readfd,"r");
  fgets (id,8,fs);
  if (strcmp(id,"DISSECT")!=0) {
    fprintf (stderr, "dissect: failure setting up pipe, wrong id (%s).\n",id);
    exit(1);
  }
  errno = 0;
  return fs;
}

static void
child (int writefd, char **argv)
{
  FILE *fs;
  
  if (writefd!=3) {
    dup2 (writefd,3);
    syschk ();
  }
  fs = fdopen (3,"w");
  fputs ("DISSECT",fs);
  fflush (fs);
  execv (argv[0], argv);
  perror (argv[0]);
  exit(1);
}

FILE *
pipe_log (char **argv)
{
  pid_t pid;
  int io[2];
  
  errno=0;
  pipe (io);       syschk ();
  
  pid = fork();    syschk ();
  
  if (pid) {
    close (io[1]); syschk ();
    return parent (io[0]);
  } else {
    close (io[0]); syschk ();
    child (io[1], argv);
    abort ();
  }
}
