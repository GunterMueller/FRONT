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

#ifndef _ELEGANT
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>

#include "scan_support.h"
#include "error.h"
#include "hash.h"
#define MALLOC malloc
#else
#include "MyStorage.h"
#include "UnixProcess.h"
#define IDENT_STRING(id)	((id)->represent)
#define count_chars TRUE
#define MALLOC MyStorage_Const_ALLOCATE
#define find_location ScanIO_FindLocation
#define Front_input_file NULL
#endif

#define _IMPL_
#include "print_support.h"

static struct s_SrcInfo _no_srcinfo \
  = { -1, -1, NULL, NULL, NULL };
SrcInfo no_srcinfo = &_no_srcinfo;

/*********/

Bool Front_pretty = TRUE;	/* Pretty printing or not */
FILE *print_file = NULL;	/* Output file for printing */
char *print_string = NULL;	/* Output string for printing */
char *print_file_name = NULL;	/* File name for printing */
Bool Source_node = TRUE;	/* Current node is a source node; */
Bool Print_html = FALSE;	/* Print in html format */
Bool Print_noref = FALSE;	/* No cross referencing */
Bool Print_layout = TRUE;	/* Layout printing */
Bool eval_comments = FALSE;     /* Comment printing */
Bool fill_src_info = FALSE;		/* Fill in src_info while printing */
Bool suppress_printing = FALSE;		/* Suppress printing */
Bool create_no_scr_info = FALSE;        /* Suppress creating of src_info */
Bool printing_to_string = FALSE;	/* Printing to string iso file */
static char *pr_string;			/* Current position in print_string */
static int print_string_size = 0;

/* Current position.
   In case of pretty printing, this is the current column.
   Otherwise, it is the total number of characters printed.
*/
static int cur_pos = 0;
static int cur_char = 0;

/* Position of the margin, only relevant for pretty printing */
static int margin = 0;

#define INDENT \
  { while (cur_pos < margin) {\
       cur_pos++; cur_char++; \
       if (Print_html) Front_outputf ("&nbsp;"); \
       else Front_outputf (" "); \
  } }

/************/

char dummy_string[4096];

int Front_outputf (char *format, ...)
{
  va_list arg_list;
  int n;

  va_start(arg_list, format);
  if (suppress_printing) {
    n = vsprintf (dummy_string, format, arg_list);    
  } else if (printing_to_string) {
    if (print_string_size>0 && print_string_size - (pr_string-print_string)<4096) {
      char *p = realloc (print_string, 2*print_string_size);
      pr_string = p + (pr_string - print_string);
      print_string_size *= 2;
      print_string = p;
    }
    n = vsprintf (pr_string, format, arg_list);    
    pr_string += n;
  } else {
    if (print_file==NULL) print_file = stdout;
    errno = 0;
    n = vfprintf (print_file, format, arg_list);
    if (errno) FrontFatalError ("%s", strerror(errno));
  }
  return n;
}

/************/

static SrcInfo all_src_info = NULL;

static void insert_all_src_info (SrcInfo s)
{
  SrcInfo *t;
  
  if (s == NULL) return;

  for (t = &all_src_info; *t != NULL; t = &(*t)->next) {
    if (SrcInfo_loc(s) > (*t)->loc) continue;
    if (SrcInfo_loc(s) == (*t)->loc) {
#if 1
      /* Same loc, keep new one, this is the one highest in the AST */
      SrcInfo_next(s) = (*t)->next;
      (*t)->next = NULL;
      *t = s;
#else
      /* Same loc, keep oldest one, this is the one lowest in the AST */
#endif
      return;
    }
    SrcInfo_next(s) = *t;
    *t = s;
    return;
  }
  *t = s;
  return;
}

#ifdef _ELEGANT
void Debug_SrcInfo (SrcInfo s)
{ if (s==NULL) {
    printf ("NIL");
    return;
  }
  printf ("loc = %d\n", SrcInfo_loc(s));
  if (SrcInfo_pre_comment(s) != NULL) {
    printf ("pre_comment = "); 
    Debug_scan_strings (SrcInfo_pre_comment(s)); printf ("\n");
  }
  if (SrcInfo_post_comment(s) != NULL) {
    printf ("post_comment = "); 
    Debug_scan_strings (SrcInfo_post_comment(s)); printf ("\n");
  }
}
#endif

SrcInfo make_post_src_info (int loc, int post)
{ 
  if (!create_no_scr_info) {
    SrcInfo s = MALLOC (sizeof(*s));
    SrcInfo_loc(s) = loc;
    SrcInfo_post_loc(s) = post;
    SrcInfo_pre_comment(s) = NULL;
    SrcInfo_post_comment(s) = NULL;
    SrcInfo_next(s) = NULL;
    if (eval_comments) insert_all_src_info (s);
    return s;
  }
  else {
    return no_srcinfo;
  }
}

SrcInfo make_src_info (int loc)
{ return make_post_src_info (loc, loc);
}

void EvalComments (void)
{
  SrcInfo s;
  
  for (s = all_src_info; s != NULL; s = SrcInfo_next(s)) {
    /* Gather pre-comments until SrcInfo_loc(s) */
    SrcInfo_pre_comment(s) = gather_comment(SrcInfo_loc(s), TRUE);
    /* Gather post-comments from SrcInfo_loc(s) until SrcInfo_next(s)->loc */
    SrcInfo_post_comment(s) = gather_comment(SrcInfo_next(s)==NULL?INT_MAX:SrcInfo_next(s)->loc, FALSE);
  }
}

/************/

static Bool do_advance = TRUE;

#define ADVANCE(x) \
  { int _adv = x; \
    if (do_advance && (pretty || Source_node)) { cur_pos += _adv; cur_char += _adv; } \
  }

void set_advance (Bool adv)
{ do_advance = adv; }

static int print_cur (char *s)
{
  if (Print_html) {
    int l = 0;
    for (; *s; s++, l++) {
      char c = *s;
      switch (c) {
        case ' ':  Front_outputf ("&nbsp;"); break;
        case '\n': Front_outputf ("<br>\n"); break;
        default:   Front_outputf ("%c", c); break;
      }
    }
    return l;
  }
  return Front_outputf ("%s", s);
}

static void print_nl (void)
{
  if (fill_src_info) {
    input_size = cur_char;
    new_input_line();
  }
  if (Print_html) Front_outputf ("<br>");
  Front_outputf ("\n");
}

static void _goto_position (int pos, Bool print)
{ int line_nr = 0;
  static scan_strings *cur_string = &first_strings;
    
  if (!do_advance) return;
  if (!pretty & !Source_node) return;
  
  if (print_file == NULL) print_file = stdout;
  
  if (pretty) {
    INDENT;
    return;
  }
  if (count_chars) {
    if (pos < cur_pos) cur_pos = pos; 
    /* pos >= cur_pos */
    while (*cur_string && (*cur_string)->pos <= cur_pos) {
      int n;
      if (print) {
        n = print_cur ((*cur_string)->string);
      } else {
        n = strlen ((*cur_string)->string);
      }
      cur_pos += n; cur_char += n;
      cur_string = &(*cur_string)->next;
    }
    if (pos > (int)cur_pos) cur_pos = pos;
  } else {
    while (pos < INT_MAX && line_nr < pos) {
      line_nr++;
      if (print) print_nl ();
      cur_pos++; cur_char++;
    }
    cur_pos = pos;
  }
}

void advance_position (int pos)
{
  _goto_position (pos, TRUE);
}

void goto_position (int pos)
{
  _goto_position (pos, FALSE);
}

unsigned int fix_margin (void)
{ 
  unsigned int m = margin;
  if (cur_pos > margin) margin = cur_pos;
  return m;
}

unsigned int get_margin (void)
{ 
  return margin;
}

void set_position (unsigned int p)
{ 
  cur_pos = p;
}

void set_margin (unsigned int m)
{ 
  margin = m;
}

void Print_Layout (String a)
{
  Bool source_node = Source_node;
  if (!Print_layout) return;
  Source_node = FALSE;
  Print_String(a);
  Source_node = source_node;
}

void Print_NL(void)
{ if (!pretty) goto_position (cur_pos);
  if (print_file == NULL) print_file = stdout;
  print_nl ();
  ADVANCE (1);
  if (!pretty) return;
  cur_pos = 0;
}

void Print_Int (Int a)
{ advance_position (cur_pos);
  ADVANCE (Front_outputf ("%d", a));
}
 
void Print_Oct (Int a)
{ advance_position (cur_pos);
  ADVANCE (Front_outputf ("0%o", a));
}

void Print_Hex (Int a)
{ advance_position (cur_pos);
  /* gcc insists of white space after a hex value */
  ADVANCE (Front_outputf ("0x%x ", a));
}

static char *special_html (char c)
{
  switch (c) {
    case '<': return "&lt;";
    case '>': return "&gt;";
    case '&': return "&amp;";
    case '"': return "&quot;";
    case ' ': return "&nbsp;";
    default:  break;
  }
  return NULL;
}

static void print_str (String a, int n)
{ int i;

  if (pretty) {
    if (n > 0 && a[n] == '\n') {
      advance_position (cur_pos);
      ADVANCE (Front_outputf ("%c", a[0]));
      print_str (&a[1], n-1);
      return;
    }
    switch (a[0]) {
      case '\n':
	Print_NL ();
	print_str (&a[1], n-1);
	return;
      case '\t':
	advance_position (cur_pos);
	for (i = 0; i < 8-cur_pos%8; i++) {
	  if (Print_html) Front_outputf ("%s", special_html(' '));
	  else Front_outputf ("%s", " ");
	}
	if (do_advance) {
	  int n = 8-cur_pos%8;
	  cur_pos += n; cur_char += n;
	}
	print_str (&a[1], n-1);
	return;
      case ' ':
      case '<':
      case '>':
      case '&':
      case '"':
        if (!Print_html) break;
	advance_position (cur_pos);
	Front_outputf ("%s", special_html(a[0]));
	if (do_advance) { cur_pos++; cur_char++; }
	print_str (&a[1], n-1);
	return;
      case 0:
	return;
      default:
	break;
    }
  }
  advance_position (cur_pos);
  ADVANCE (Front_outputf ("%s", a));
}

void Print_String (String a)
{ print_str (a, strlen(a)-1);
}

void Print_Keyword (String a)
{ if (Print_html) {
    Front_outputf ("<b>");
    print_str (a, strlen(a)-1);
    Front_outputf ("</b>");
  } else {
    print_str (a, strlen(a)-1);
  }
}

void Print_Float (Float a)
{ advance_position (cur_pos);
  ADVANCE (Front_outputf ("%#g", a));
}

void Print_Ident (Ident a)
{ advance_position (cur_pos);
  ADVANCE (Front_outputf ("%s", IDENT_STRING(a)));
}

void Print_Bool (Bool a)
{ advance_position (cur_pos);
  ADVANCE (Front_outputf (a ? "TRUE" : "FALSE"));
}

static Bool isprint (char c)
{
  return c >= ' ' && c != 127;
}

void Print_Char (Char a1)
{ unsigned char a = a1;
  advance_position (cur_pos);
  switch (a) {
    case '\a': 
      ADVANCE (Front_outputf ("'\\a'")); break;
    case '\b': 
      ADVANCE (Front_outputf ("'\\b'")); break;
    case '\f': 
      ADVANCE (Front_outputf ("'\\f'")); break;
    case '\n': 
      Front_outputf ("'\\n'");
      ADVANCE (3); break;
    case '\r': 
      Front_outputf ("'\\r'");
      ADVANCE (3); break;
    case '\t': 
      ADVANCE (Front_outputf ("'\\t'")); break;
    case '\v': 
      ADVANCE (Front_outputf ("'\\v'")); break;
    case '\'': 
      ADVANCE (Front_outputf ("'\\''")); break;
    case '\"': 
      ADVANCE (Front_outputf ("'\\\"'")); break;
    case '\?': 
      ADVANCE (Front_outputf ("'\\?'")); break;
    case '\\': 
      ADVANCE (Front_outputf ("'\\\\'")); break;
    default:
      if (isprint(a)) {
        ADVANCE (Front_outputf ("'%c'", a));
      } else {
	ADVANCE (Front_outputf ("'\\%o'", a)); break;
      }
  }
}

char *Print_unstring (char* s)
{
  int n = strlen (s);
  char *t = MALLOC (strlen (s)+1);
  int i, j;
  
  for (i = 0, j = 0; i < n; i++) {
    switch (s[i]) {
      case '"':
        if (i==0 || i == n-1) break;
        t[j++] = s[i];
	break;	
      case '\\':
        switch (s[++i]) {
	  case 'a': t[j++] = '\a'; continue;
	  case 'b': t[j++] = '\b'; continue;
	  case 'n': t[j++] = '\n'; continue;
	  case 'r': t[j++] = '\r'; continue;
	  case 't': t[j++] = '\t'; continue;
	  case 'f': t[j++] = '\f'; continue;
	  case 'v': t[j++] = '\v'; continue;
	  default:t[j++] = s[i]; continue;
	}
      case '?':
        switch (s[++i]) {
	  case 'n': 
	    if (cur_pos > margin) t[j++] = '\n';
	    continue;
	  default:t[j++] = s[i];
	}
        t[j++] = s[i];
	break;
      default:
        t[j++] = s[i];
	break;
    }
  }
  t[j] = 0;
  return t; 
}


#ifndef _ELEGANT
void Print_List_Int (List_Int me)
{ { unsigned int margin;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Int (List_Int_data(me));
    PRINT_List_Int (List_Int_next(me));
    set_margin (margin);
  }
}

void Print_List_String (List_String me)
{ { unsigned int margin;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_String (List_String_data(me));
    PRINT_List_String (List_String_next(me));
    set_margin (margin);
  }
}

void Print_List_Ident (List_Ident me)
{ { unsigned int margin;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Ident (List_Ident_data(me));
    PRINT_List_Ident (List_Ident_next(me));
    set_margin (margin);
  }
}

void Print_List_Bool (List_Bool me)
{ { unsigned int margin;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Bool (List_Bool_data(me));
    PRINT_List_Bool (List_Bool_next(me));
    set_margin (margin);
  }
}

void Print_List_Char (List_Char me)
{ { unsigned int margin;
    if (me == NULL) return;
    margin = fix_margin ();
    PRINT_Char (List_Char_data(me));
    PRINT_List_Char (List_Char_next(me));
    set_margin (margin);
  }
}
#endif

/***********/

/* Html generation */
void start_label (void *def)
{ if (!Print_html) return;
  Front_outputf ("<a NAME = \"x%p\">", def);
}

void end_label (void)
{ if (!Print_html) return;
  Front_outputf ("</a>");
}

void start_href (int loc, void *ref)
{ int line, pos;
  Ident file;
  
  if (!Print_html || Print_noref) return;
  find_location (loc, &line, &pos, &file);
  
  if (file == Front_input_file) {
    Front_outputf ("<a href=\"#x%p\">", ref);
  } else {
    Front_outputf ("<a href=\"%s#%d\">", IDENT_STRING(file), line);
  }
}

void end_href (void)
{ if (!Print_html || Print_noref) return;
  Front_outputf ("</a>");
}


#define TEST_PRETTY (!pretty)

Bool suppress_comment = FALSE;

void print_comment (scan_strings s)
{ int pos = cur_pos;

  if (suppress_comment) return;
  for (; s; s = SrcInfo_next(s)) {
    if (TEST_PRETTY && s->pos < cur_pos) cur_pos = s->pos;
    else advance_position (s->pos);
    Print_String (s->string);
    if (!TEST_PRETTY && cur_pos > pos) Print_NL();
  }
  if (TEST_PRETTY && cur_pos < pos) cur_pos = pos;
}

void set_src_info (SrcInfo *info)
{ if (!fill_src_info) return;
  if (*info == NULL || *info == no_srcinfo) {
    *info = make_src_info (cur_char);
  } else {
    SrcInfo_loc(*info) = SrcInfo_post_loc(*info) = cur_char;
  }
}

/*******************/

Bool _open_print_file (char *fn, Bool pr, Bool print_to_string)
{
  char *title = "Generated"; /* make parameter or global out of this */
  pretty = pr;
  
  cur_pos = 0;
  margin = 0;
  
  printing_to_string = print_to_string;
  if (print_to_string) {
    print_string = fn;
    if (!print_string) {
      print_string = malloc (4096);
      print_string_size = 4096;
    } else {
      print_string_size = -1;
    }
    pr_string = print_string;
    print_file_name = "string";
  } else {
  
    if (strlen(fn) == 0) {
      print_file = stdout;
      print_file_name = "stdout";
    } else {
      print_file_name = fn;
      print_file = fopen (fn, "wb");
      if (print_file == NULL) {
        fprintf (stderr, "Cannot open file %s\n", fn);
#ifndef _ELEGANT
        return FALSE;
#else
	UnixProcess_Exit (UnixProcess_Failure);
#endif
      }
    }
  }
  if (Print_html) {
    Front_outputf ("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n");
    Front_outputf ("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html\">\n");
    Front_outputf ("<title>%s</title></head><body>\n", title);
  }
  return TRUE;
}


Bool open_print_file (char *fn, Bool pr)
{ return _open_print_file (fn, pr, FALSE); }

Bool open_print_string (char *s, Bool pr)
{ return _open_print_file (s, pr, TRUE); }

void close_print_file (void)
{
  if (Print_html) {
    Front_outputf ("</body></html>\n");
  }
  if (!printing_to_string && print_file!=stdout) fclose (print_file);
  if (printing_to_string) pr_string[0] = 0;
  print_file = stdout;
}

void close_print_string (void)
{
  close_print_file ();
  printing_to_string = FALSE;
}

#ifdef _ELEGANT

void print_support_InitGlobals (void)
{ 
  print_file = stdout;
}

#endif

void add_scan_info (char *fn, void *root, void (*pr) (void*), Bool print)
{ Bool sp = suppress_printing;
  
  count_chars = TRUE;
  fill_src_info = TRUE;
  suppress_printing = !print;
  scan_init (fn);
  if (open_print_file (fn, TRUE)) {
    pr (root);
    close_print_file ();
  }
  suppress_printing = sp;
  fill_src_info = FALSE;
}

char *
get_loc_file(int loc)
{
  int line, pos;
  Ident file;
  
  find_location (loc, &line, &pos, &file);
  return Ident_name (file);
}

char *
get_loc_line(int loc)
{
  int line, pos;
  Ident file;

  find_location (loc, &line, &pos, &file);
  return Front_StrAllocf("%d",line);
}

char *
get_loc_col(int loc)
{
  int line, pos;
  Ident file;

  find_location (loc, &line, &pos, &file);
  return Front_StrAllocf("%d",pos);
}
