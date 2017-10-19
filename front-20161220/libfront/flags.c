/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

#include "flags.h"
#include "text.h"
#include "error.h"
#include "mem.h"

static fe_cli_flag *Flags=NULL;
static int NumFlags=0;
static int Sorted=0;
static int use_regexp=0;
static int flagErrors=0;

char *fe_usage_string="Usage: %s [flags] file ...\n";

/* ----------------------------------------------------------------------------
 * Compare used in sorting the flag table
 */
static int
qsort_compare(fe_cli_flag *a, fe_cli_flag *b)
{
  return strcmp(a->name,b->name);
}

/* ----------------------------------------------------------------------------
 * Sort the flags alphabetically according to name
 */
static void
sort_flags(void)
{
  qsort(Flags,NumFlags,sizeof(fe_cli_flag),(void*)qsort_compare);
}

/* ----------------------------------------------------------------------------
 * Function to call to display help message from CLI parsing
 */
int
fe_help_flag(int argc, char *argv[])
{
  argc=(int)argv[0]; /* just using them */
  fe_usage();
  return 0;
}

/* ----------------------------------------------------------------------------
 * Function to check how many unrecognized arguments were encountered
 */
int
fe_flag_errors()
{ return flagErrors; }

/* ----------------------------------------------------------------------------
 * Print the help message for the program
 */
void
fe_usage(void)
{
  const char *name = NULL;
  int i, k;
  int len = 0;
  
  if(!Sorted) sort_flags();
  printf(fe_usage_string, fe_package);

  /* Compute maximum length of switches, used for alignment */
  for (i = 0; i < NumFlags; i++) {
    int l;
    
    name=Flags[i].usage_name;
    if(name==DFLT_NAME) name=Flags[i].name;
    l =strlen (name);
    if (l > len) len = l;
  }
  len += 4;

  for (i = 0; i < NumFlags; i++) {
    if (i>0 && strcmp(Flags[i].name,Flags[i-1].name)==0) continue;
    name=Flags[i].usage_name;
    if(!name) name=Flags[i].name;
    if (!Flags[i].explain[0]) continue; 
    printf("  %-*s", len, name);
    puts (Flags[i].explain[0]);
    for (k = 1; Flags[i].explain[k] && k < FE_USAGE_LINES; k++) {
      printf("  %-*s", len, "");
      puts (Flags[i].explain[k]);
    }
  }
  exit(1);
}

/* ----------------------------------------------------------------------------
 * Register commandline flags for parsing
 */
void
fe_register_flags(int count, const fe_cli_flag *args)
{
  Flags = fe_realloc(Flags,(NumFlags+count)*sizeof(fe_cli_flag));
  memcpy(Flags+NumFlags,args,count*sizeof(fe_cli_flag));
  NumFlags+=count;
}

/* ----------------------------------------------------------------------------
 * Find FLAG in the table.
 */
fe_cli_flag *
fe_find_flag(char *flag, int *start)
{
  int i;
  
  for (i=*start; i<NumFlags; i++) {
    if (strcmp (Flags[i].name, flag)==0) break;
  }
  *start=i;
  if (i<NumFlags) return &Flags[i];
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Print regex error and quit
 */
static void
re_error(int status, regex_t *re)
{
  int size;
  char *error;

  if(status==0) return;
  size = regerror (status, re, NULL, 0);
  error = fe_malloc(size);
  regerror (status, re, error, size);
  fe_error ("%s\n",error);
  abort();
}

/* ----------------------------------------------------------------------------
 * Find FLAG in the table, matches FLAG against the regulare expression in the
 * table
 */
fe_cli_flag *
fe_re_find_flag(char *flag, int *start)
{
  int i, status;
  
  for (i=*start; i<NumFlags; i++) {
    char *str = fe_strcat("^", Flags[i].name);
    regex_t re;

    str = fe_strappend(str,"$");
    status = regcomp (&re, str, REG_EXTENDED|REG_NOSUB);
    re_error(status, &re);
    if (regexec (&re, flag, 0, NULL, 0)==0) break;
    regfree(&re);
  }
  *start=i;
  if (i<NumFlags) return &Flags[i];
  return NULL;
}

/* ----------------------------------------------------------------------------
 * Find FLAG in the table
 */
static fe_cli_flag *
find_flag (char *flag, int *start)
{
  if (!use_regexp) return fe_find_flag (flag, start);
  return fe_re_find_flag (flag, start);
}

/* ----------------------------------------------------------------------------
 * Tell the cli parser to use regular expressions
 */
void
fe_flags_use_regexp(void)
{
  use_regexp=1;
}

/* ----------------------------------------------------------------------------
 * Parse command line flags
 */
int
fe_parse_flags(int argc, char *argv[])
{
  fe_cli_flag *flag;
  int i;
  int j=1;
  flagErrors=0;
  
  for(i=1; i<argc; i++) {
    if(argv[i][0]!='-') {
      argv[j++]=argv[i];
    } else {
      int start = 0;
      int found = 0;
      int c=0;
      while ((flag = find_flag(argv[i], &start))) {
        if(flag->function!=NULL) c=flag->function(argc-i, &argv[i]);
        else if(flag->boolean!=NULL) *flag->boolean = 1;
        start ++;
        found = 1;
      }
      i+=c;
      if(!found) {
	fe_error("unrecognized option `%s'",argv[i]);
	flagErrors++;
      }
    }
  }
  return j;
}
