/*
 * Copyright (C) 2000-2005 Philips Electronics N.V.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 */
#include <stdio.h>
#include <string.h>
#include "flags.h"

#define MAX_LINES 5

Bool search_ops = FALSE;
Bool allow_undeclared_ops = FALSE;
Bool gen_test = FALSE;
Bool tree = FALSE;
Bool ExtraWarnings = FALSE;

char *input_file = NULL;
char *outfile = NULL;
char *id_string = NULL;

static int function_name    	(char **argv, int argc, int i);
static int output_name    	(char **argv, int argc, int i);
static int id_name    		(char **argv, int argc, int i);
static int help    		(char **argv, int argc, int i);

static void usage (FILE *f);

/* Information describing command switches */

typedef struct {
  char *sw;			/* Name of switch */
  Bool *b;			/* Boolean to be set to true */
  int (*f) (char **, int, int);	/* Function to be called */
  char *name;			/* Name to be printed in usage */
  char *explain[MAX_LINES];	/* Explanation to be printed in usage */
} command_switch;

static command_switch switches[] = 
{ 
  { "-search_ops",          	&search_ops, 		NULL,      		"-search_ops",             	{ "search operation names" } },
  { "-allow_undeclared_ops",	&allow_undeclared_ops, 	NULL,      		"-allow_undeclared_ops",	{ "allow undeclared operators" } },
  { "-gen_test",         	&gen_test, 		NULL,      		"-gen_test",             	{ "generate node concistency test function" } },
  { "-tree",     	    	&tree , 		NULL,      		"-tree",             		{ "transform tree rather than DAG" } },
  { "-w",         		&NoWarnings, 		NULL,      		"-w",             		{ "disable warnings" } },
  { "-w+",          		&ExtraWarnings, 	NULL,      		"-w+",             		{ "generate extra warnings" } },
  { "-f",          		NULL, 			function_name,      	"-f <name>",             	{ "name of root function" } },
  { "-o",          		NULL, 			output_name,      	"-o <file>",             	{ "name of output file" } },
  { "-i",          		NULL, 			id_name,      		"-i <name>",             	{ "name of optimize functions, default=rule" } },
  { "-help",          		NULL, 			help,      		"-help",            	 	{ "print this message" } },
};

static int function_name (char **argv, int argc, int i)
{ i++;
  if (i >= argc) FrontError (TRUE, "Missing function name");
  else opt_name = argv[i];
  return i;
}

static int output_name (char **argv, int argc, int i)
{ i++;
  if (i >= argc) FrontError (TRUE, "Missing function name");
  else outfile = argv[i];
  return i;
}

static int id_name (char **argv, int argc, int i)
{ i++;
  if (i >= argc) FrontError (TRUE, "Missing function name");
  else id_string = argv[i];
  return i;
}


static int help (char **argv, int argc, int i)
{ usage (stdout);
  NOT_USED(argv);
  NOT_USED(argc);
  return i; 
}

static char *myself = "doggy";

#define NUM_SWITCHES ((int)(sizeof(switches) / sizeof(command_switch)))

/* Print usage by interpreting the switches list */
static void usage (FILE *f)
{ int i, j, k;
  int len = 0;
  
  fprintf (f, "Usage: %s switch* input_file\n", myself);

  /* Compute maximum length of switches, used for alignment */
  for (i = 0; i < NUM_SWITCHES; i++) {
    int l = strlen (switches[i].name);
    if (l > len) len = l;
  }
  len += 4;

  for (i = 0; i < NUM_SWITCHES; i++) {
    int l = strlen (switches[i].name);
    fprintf (f, "  %s", switches[i].name);
    for (k = 0; k < MAX_LINES; k++) {
      if (switches[i].explain[k] == NULL) break;
      for (j = l; j < len; j++) fprintf (f, " ");  /* Align */
      fprintf (f, "%s\n", switches[i].explain[k]); /* Print explanation line */
      l = 0;
    }
  }
  exit(1);
}

/* Interpret one switch argv[i], return index of next switch */
static int parse_flag (char **argv, int argc, int i)
{
  int j, k = i;
  static Bool error_given = FALSE;
   
  if (argv[i][0] != '-') {
    if (input_file == NULL || strcmp(input_file,"stdin")==0) input_file = argv[i];
    return i+1;
  }
  
  for (j = 0; j < NUM_SWITCHES; j++) {
    if (strcmp (argv[i], switches[j].sw) != 0) continue;
    if (switches[j].b != NULL) {
      *switches[j].b = TRUE;
    } else {
      k = switches[j].f (argv, argc, i);
    }
    return k+1;
  }

  FrontError (TRUE, "Switch %s discarded", argv[i]);
  if (!error_given) usage (stderr);
  error_given = TRUE;
  
  return i+1;
}

void parse_flags (int argc, char **argv)
{ int i;

  myself = argv[0];
  
  for (i=1; i < argc; i = parse_flag (argv, argc, i)) {}
}

