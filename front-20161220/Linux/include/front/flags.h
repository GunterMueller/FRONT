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
#ifndef _libfront_flags_h
#define _libfront_flags_h

#define FE_USAGE_LINES 4
#define DFLT_NAME NULL

typedef struct {
  const char *name;                     /* Name of switch */
  int  *boolean;                        /* Boolean to be set to true */
  int (*function) (int, char **);	/* Function to be called */
  const char *usage_name;	        /* Name to be printed in usage */
  const char *explain[FE_USAGE_LINES];  /* Explanation to be printed in usage */
} fe_cli_flag;

extern char *fe_usage_string;

/* Display usage, use as function for help option */
int fe_help_flag(int argc, char *argv[]);

/* Display usage and exit */
void fe_usage(void);

/* Register a flag table. Successive calls add to the table, there's no checking
 * for duplicates
 */
void fe_register_flags(int count, const fe_cli_flag *args);

/* Find flag information of FLAG, returns NULL if flag is not known */
fe_cli_flag *fe_find_flag(char *flag, int *start);
fe_cli_flag *fe_re_find_flag(char *flag, int *start);

/* Tell the CLI parser to use regular expressions */
void fe_flags_use_regexp(void);

/* Check if any unrecognized arguments where encountered (and how many) */
int fe_flag_errors(void);

/* Parse the command line. Returns new size of argv, argv contains remaining
 * non-flag arguments
 */
int fe_parse_flags(int argc, char *argv[]);

#endif /* _libfront_flags_h */
