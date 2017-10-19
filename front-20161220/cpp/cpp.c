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
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <front/mem.h>
#include <front/error.h>
#include <front/scan_support.h>
#include <front/egg_msg.h>
#include "pp.h"
#include "emit.h"
#include "cpp.h"
#include "errors.h"

#define _STR(x) # x
#define STR(x) _STR(x)

typedef struct s_files *files;

struct s_files {
  const char *file;
  files       tail;
};

static files pp_files = NULL;
static sequence TokenSeq = NULL;
static tokens TokenString = NULL; /* preprocessing result */ 

static int opt_define   (int argc, char *argv[]);
static int opt_incpath  (int argc, char *argv[]);
static int opt_include  (int argc, char *argv[]);
static int opt_c99      (int argc, char *argv[]);
static int opt_gnu      (int argc, char *argv[]);
static int opt_trigraph (int argc, char *argv[]);
static int opt_inhibit_expansion (int argc, char *argv[]);
static int opt_inhibit_linemarkers (int argc, char *argv[]);
static int opt_error_mode(int argc, char **argv);
static int opt_list_errors(int argc, char **argv);

static int done1 = 0;
static int done2 = 0;
static int done3 = 0;
static int done4 = 0;

fe_cli_flag libcpp_flags[] = {
  { "-D.*", NULL,              opt_define,             "-D<macro>",             { "define a preprocessing macro" } },
  { "-I.*", NULL,              opt_incpath ,           "-I<dir>",               { "add <dir> to the include path" } },
  { "-include", NULL,          opt_include,            "-include <file>",       { "preprocess <file> before the input" } },
  { "-cpp-c99", NULL,          opt_c99,                DFLT_NAME,              { "enable c99 compatibility in the preprocessor" } },
  { "-cpp-gnu", NULL,          opt_gnu,                DFLT_NAME,              { "set certain Gnu defines in the preprocessor" } },
  { "-cpp-trigraph", NULL,     opt_trigraph,           DFLT_NAME,         { "translate trigraphs." } },
  { "-X.*", NULL,       opt_error_mode,    "-X<error> <mode>",  { "change the relevance of an error message", "mode is one of {error,warning,disabled}" } },
  { "-list-errors", NULL, opt_list_errors, DFLT_NAME,   { "list all errors and their mode" } },
  { "-P", NULL,               opt_inhibit_linemarkers, DFLT_NAME, { "inhibit generation of linemarkers in output" } },
  { "-inhibit-expansion", NULL, opt_inhibit_expansion, DFLT_NAME, { "do not expand macros (useful in combination with list-defines)" } },
};
const int num_libcpp_flags=(sizeof(libcpp_flags) / sizeof(*libcpp_flags));

/* ------------------------------------------------------------------------- */
static int
opt_define(int argc, char *argv[])
{
  NOT_USED(argc);
  CPP_cli_define (&argv[0][2]);
  return 0;
}

/* ------------------------------------------------------------------------- */
static int
opt_incpath(int argc, char *argv[])
{
  NOT_USED(argc);
  CPP_include_path (&argv[0][2]);
  return 0;
}

/* ------------------------------------------------------------------------- */
static int
opt_include(int argc, char *argv[])
{
  if (argc < 2) cpp_missing_argument(NULL, argv[0]);
  else CPP_cli_include (argv[1]);
  return 1;
}

/* ------------------------------------------------------------------------- */
static int
opt_c99(int argc, char *argv[])
{
  NOT_USED(argc);
  NOT_USED(argv);
  CPP_c99();
  return 0;
}

/* ------------------------------------------------------------------------- */
static int
opt_gnu(int argc, char *argv[])
{
  NOT_USED(argc);
  NOT_USED(argv);
  CPP_gnu();
  return 0;
}

/* ------------------------------------------------------------------------- */
static int
opt_trigraph(int argc, char *argv[])
{
  NOT_USED(argc);
  NOT_USED(argv);
  CPP_trigraphs();
  return 0;
}

/* ------------------------------------------------------------------------- */
static
int opt_inhibit_expansion (int argc, char *argv[]) 
{
  NOT_USED(argc);
  NOT_USED(argv);  
  CPP_inhibit_expansion();
  return 0;
}

static int opt_inhibit_linemarkers (int argc, char *argv[]) 
{
  NOT_USED(argc);
  NOT_USED(argv);  
  CPP_inhibit_linemarkers();
  return 0;
}

static int opt_error_mode(int argc, char **argv)
{
  if (argc < 2) cpp_missing_argument(NULL, argv[0]);
  else  cpp_cpp_parse_option (argv[0]+2, argv[1]);
  return 1;

}

static int opt_list_errors(int argc, char **argv)
{
  NOT_USED(argc);
  NOT_USED(argv);
  cpp_cpp_list_options();
  return 0;
}

/* ----------------------------------------------------------------------------
 * Initialize the cpp
 */
void
CPP_initialize(void)
{
  if (done1 == 1) return;
  init_define();
  done1 = 1;
}

void
CPP_finish(void)
{
  /* clear include path and defines */
  clear_include();
  clear_define();

  done1 = 0;
  done2 = 0;
  done3 = 0;
  done4 = 0;
}

/* ----------------------------------------------------------------------------
 * Add standard predefines
 */
void
CPP_predefines(int gnu)
{
  if (!done2) {
    CPP_predefine("__STDC__","1");
    CPP_predefine("__STRICT_ANSI__","1"); /* c89 */
    done2 = 1;
  }
  if (!done3 && enable_c99) {
    CPP_predefine("__STDC_VERSION__","199901L");
    done3 = 1;
  }
  if (!done4 && gnu) {
    CPP_predefine("__USER_LABEL_PREFIX__",""); 
    CPP_predefine("__REGISTER_PREFIX__","");
    CPP_predefine("__HAVE_BUILTIN_SETJMP__",STR(__HAVE_BUILTIN_SETJMP__));
    CPP_predefine("__PTRDIFF_TYPE__",STR(__PTRDIFF_TYPE__));
    CPP_predefine("__SIZE_TYPE__",STR(__SIZE_TYPE__));
    CPP_predefine("__WCHAR_TYPE__",STR(__WCHAR_TYPE__));
    CPP_predefine("__WINT_TYPE__",STR(__WINT_TYPE__));
    done4 = 1;
  }
/*   CPP_predefine("__VERSION__", "\"3.2.1\""); */
}

/* ----------------------------------------------------------------------------
 * Enable C99 compatability
 */
void
CPP_c99(void)
{
  enable_c99 = 1;
}

/* ----------------------------------------------------------------------------
 * Enable Gnu compatability
 */
void
CPP_gnu(void)
{
  cpp_gnu = 1;
}

void
CPP_inhibit_expansion(void)
{ 
  cpp_inhibit_expansion = TRUE;
}

void
CPP_inhibit_linemarkers(void)
{
  cpp_inhibit_linemarkers = TRUE;
}

/* ----------------------------------------------------------------------------
 * Enable trigraph translation
 */
void
CPP_trigraphs(void)
{
  enable_trigraph = 1;
}

/* ----------------------------------------------------------------------------
 * Set output format to visual studio format: <file>(<pos>):<msg>
 */
void
CPP_visual_studio(void)
{
  visual_studio_compatible = 1;
}

/* ----------------------------------------------------------------------------
 * Keep tokens original location
 */
void
CPP_deep_location(void)
{
  deep_location = 1;
}

/* ----------------------------------------------------------------------------
 * Emit tokens at their original location (when possible)
 */
void
CPP_original_location(void)
{
  emit_to_original_loc = 1;
}

/* ----------------------------------------------------------------------------
 * Predefine an alias
 */
void
CPP_predefine(char *alias, char *repl)
{
  new_alias (id_token(alias), scan_string(repl, "<built-in>", 1, 1, 1, 0));
}

/* ----------------------------------------------------------------------------
 * Add a directory to the include path
 */
void
CPP_include_path(const char *dir)
{
  append_include(dir);
}

/* ----------------------------------------------------------------------------
 * Add standard include dirs to the include path
 */

static void get_gnu_paths(void);
static char *make_include_path(char *s, char *t);
static char *strrstr (char *s, char *t);

void
CPP_std_include_path(void)
{
  /* order of include paths is relevant */

  if (getenv("CPATH"))
      CPP_include_path (getenv("CPATH"));
  if (getenv("C_INCLUDE_PATH"))
      CPP_include_path (getenv("C_INCLUDE_PATH"));
  if (getenv("CPLUS_INCLUDE_PATH"))
      CPP_include_path (getenv("CPLUS_INCLUDE_PATH"));

  /* some default paths under Unix */
  CPP_include_path ("/usr/local/include");
  CPP_include_path ("/usr/include");

  if (cpp_gnu)
    get_gnu_paths ();

}

static void
get_gnu_paths(void)
{
  FILE *p;
  static char const * const delimiters = " :\t\n\r";
  static char line[1024];
  char *path1 = NULL;
  char *path2 = NULL;

  /* We ask gcc to tell where it reads its specs from. From the path to */
  /* that file we derive two paths where we expect include directories. */

  if ((p = popen ("gcc -v 2>&1", "r")) == NULL) fe_error ("Can't execute 'gcc -v'");
  while (fgets (line, sizeof (line), p))
  {
    if (strstr (line, "specs"))
    {
      char *lib, *specs;
      char *s = strtok (line, delimiters);
      while (s && (s[0] != '/')) s = strtok (NULL, delimiters);
      if (!s) {
        fe_error ("Can't retrieve path from the output of 'gcc -v'");
        return;
      }

      if ((lib = strstr (s, "/lib/")) == NULL) fe_error ("While reading output of 'gcc -v': can't find lib portion in '%s'.", s);
      if ((specs = strrstr (s, "/specs")) == NULL) fe_error ("While reading output of 'gcc -v': can't find specs portion in '%s'.", s);

      path1 = make_include_path (s, lib);
      path2 = make_include_path (s, specs);
      CPP_include_path (path1);
      CPP_include_path (path2);
      break;
    }
  }
  pclose (p);

  if (!path1 || !path2) fe_error ("Can't retrieve paths from the output of 'gcc -v'");
}

static char *
make_include_path(char *s, char *t)
{
  int len1 = t - s;
  int len2 = strlen ("/include");
  char *path = fe_malloc (len1 + len2 + 1);
  sprintf (path, "%*.*s/include", len1, len1, s);
  return path;
}

/* Hmm... why isn't this in <string.h>?? */
/* This is not the most efficient implementation - it's probably the simplest. */

static char *
strrstr (char *s, char *t)
{
  char *r = NULL;
  if (!s || !t) return NULL;
  while ((s = strstr (s, t))) r = s++;
  return r;
}

/* ----------------------------------------------------------------------------
 * command line define an alias
 */
static int
cpp_cli_define(char *def)
{
  char *par;
  token name;
  tokens args = NULL;
  int done;
  int i;

  i = strcspn(def, "=(");
  switch (def[i]) {
  case '=':
    def[i] = 0;
    new_alias (id_token(def), scan_string(&def[i+1], "<command line>", 1, 1, 1, 0));
    return 1;
  case 0:
    new_alias (id_token(def), scan_string("1", "<command line>", 1, 1, 1, 0));
    return 1;
  case '(':
    def[i] = 0;
    name = id_token(def);
  }
  /* def[i]=='(' */
  done = 1;
  while(!done) {
    par = &def[i+1];
    i = strcspn(par,",)=");
    switch(def[i]) {
    case '=': done = 1; break;
    case ')':
    case ',':
      def[i]=0;
      args = append_token(args, id_token(par));
      break;
    case 0:
      return 0;
    }
  }
  new_macro (name, args, scan_string (&def[i+1], "<command line>", 1, 1, 1, 0));
  return 1;
}

int
CPP_cli_define(char *def)
{
  if (!cpp_cli_define (def)) {
    fe_error ("Mal-formed -D option: '%s'.", def);
    return 0;
  }
  return 1;
}

/* ----------------------------------------------------------------------------
 * Add a command-line -include file
 */
void
CPP_cli_include (const char *file)
{
  files me;
  files end;

  if (!file) return;
  me = fe_malloc(sizeof (*me));
  me->file = file;
  me->tail = NULL;
  for (end = pp_files; end && end->tail; end = end->tail);
  if (!end) end = pp_files = me;
  else      end->tail = me;
}

/* ----------------------------------------------------------------------------
 * Pre-process FILENAME (and any files added with CPP_cli_include)
 */
static int
cpp_preprocess(const char *filename)
{
  File     file = NULL;
  tokens   ts = NULL;

  if (!filename) return 0;
  file = new_file (filename, SEARCH_CURDIR);

  if (!file) {
    fprintf (stderr, "File not found: %s\n", filename);
    return 0;
  }
  ts = read_file (file, 0);

  TokenSeq = new_sequence (ts, 0);
  pp_sequence (TokenSeq);
  TokenString = cat_tokens(TokenString, TokenSeq->start);
  return !egg_print_messages ();
}

int
CPP_preprocess(const char *filename)
{
  TokenString = NULL;  
  CPP_cli_include (filename);
  while(pp_files) {
    if (!cpp_preprocess (pp_files->file)) return 0;
    pp_files = pp_files->tail;
  }
#ifdef AMBER
  pp_pragmas (&TokenString);
#endif
  start_fill (TokenString);
  return 1;
}

/* ----------------------------------------------------------------------------
 * Pre-process STRING, act as if it is from FILENAME
 */
int
CPP_preprocess_string(const char *filename, char *string)
{
  tokens ts = scan_string (string, filename, 1, 0, 1, 0);
  TokenSeq = new_sequence (ts, 0);
  pp_sequence (TokenSeq);
  TokenString = TokenSeq->start;
#ifdef AMBER
  pp_pragmas (&TokenString);
#endif
  start_fill (TokenString);
  return !egg_print_messages();
}

/* ----------------------------------------------------------------------------
 * Set the current location number
 */
void
CPP_set_location(int loc)
{
  FilePos = loc;
}

/* ----------------------------------------------------------------------------
 * Write the last pre-processed file to OUT
 */
void
CPP_emit(FILE *out)
{
  emit_tokens_optimized (out, TokenString);
}

/* ----------------------------------------------------------------------------
 * Write upto MAX characters of the last pre-processed file to BUF,
 * returns the number of characters actually written
 */
int
CPP_output(char *buf, int max)
{
  return emit_fill(buf, max);
}

void
CPP_find_location(int loc, int *line, int *pos, identifier *file)
{
  token t = find_token(loc);
  if (t) {
    int d = loc - t->pos;
    *line = t->line;
    *pos  = t->col + d;
    *file = t->file->name ? Make_identifier(t->file->name) : Make_identifier("stdin");
  } else {
    _find_location (loc, line, pos, file);
  }
}

/* ----------------------------------------------------------------------------
 * Retrieve the expansion of alias-kind #define SYMBOL, as a text string.
 */
char *
CPP_alias(const char *symbol)
{
  return get_alias (symbol);
}

/* ----------------------------------------------------------------------------
 * List all #defines and #undefs unexpanded on stderr.
 */
void
CPP_list_defines()
{
  defines defs;
  for (defs = all_defines (); defs; defs = defs->tail)
  {
    define def = defs->head;
    fprintf (stderr, "%s\n", text_define (def));
  }
}

/* ----------------------------------------------------------------------------
 * List all include paths on stderr.
 */
void
CPP_list_incpaths()
{
  list_includes();
}
