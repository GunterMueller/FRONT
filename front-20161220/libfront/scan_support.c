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
#include <assert.h>
#include <string.h>
#include "support.h"
#include "text.h"
#include "scan_support.h"
#include "print_support.h"
#include "error.h"
#include "hash.h"

#define RESIZE(a,s) \
{ s *= 2; a = realloc (a, s*sizeof (a[0])); }

/*****/

int (*yy_input)(void) = NULL;
YYLTYPE *p_yylloc;

int input_line_nr = 1;
int input_size = 0;
Bool count_chars = FALSE;

Bool no_scan_strings = FALSE;

scan_strings first_strings = NULL;
scan_strings *last_strings = &first_strings;
static scan_strings last_string = NULL;

Ident Front_input_file;

/*****/

/* Mapping of absolute line number to absolute position */
static int *line_index = NULL;
static int line_size = 2048;

/* Mapping of line directive to abs line, rel line and file name */
static struct filelines { 
	int   absline;
	int   relline;
	Ident file_id;
} *file_index = NULL;

static int file_size = 2048;
static int filenrcnt = -1;
static Ident cur_file;

/*****/
/* ----------------------------------------------------------------------------
 * TRUE if S is an ASCII octal digit
 */
static Bool
isodigit(char s)
{
  return '0'<=s && s<='7';
}

/* ----------------------------------------------------------------------------
 * TRUE if S is an ASCII decimal digit
 */
static Bool
isdigit(char s)
{
  return '0'<=s && s<='9';
}

/* ----------------------------------------------------------------------------
 * TRUE if S is an ASCII hex digit
 */
static Bool
isxdigit(char s)
{
  return ('0'<=s && s<='9') || ('a'<=s && s<='f') || ('A'<=s && s<='F');
}

static char tolower (char s)
{ int c = s-'A';
  if (c < 0) return s;
  if (c >= 26) return s;
  return 'a'+s;
}

/**********/

void new_input_line (void)
{ static int pos = 0;
  int new_pos;
  new_pos = input_size;
#if 0
  printf ("Line %d, pos %d, rel %d\n", input_line_nr, pos, new_pos-pos);
#endif
  pos = new_pos;
  input_line_nr++;
  if (!count_chars) {
    p_yylloc->first_line++;
    return;
  }
  if (input_line_nr >= line_size) RESIZE (line_index, line_size);
  if (input_line_nr == 2) {
    /* First time */
    line_index[0] = line_index[1] = 0;
  }
  line_index[input_line_nr] = pos;
}

void set_first_line (int i)
{
  if (p_yylloc != NULL) {
    p_yylloc->first_line = i;
    p_yylloc->last_line = i;
  }
#if 0
  input_size = i;
#endif
}

void find_position 
(int ch, int *line, int *pos)
{ int l, h=0, m;
  if (ch == 0)
  { *line = 0;
    *pos = 0;
    return;
  }
  if (line_index[input_line_nr] < ch)
  { *line = input_line_nr; }	/* past last line */
  else
  { l = 0;
    h = input_line_nr;
    while (l < h-1)
    { /* line_index[l] < ch <= line_index[h] */
      m = (l+h) / 2; /* l < m < h */
      if (line_index[m] >= ch) { h = m; }
      else                     { l = m; }
    }
    /* line_index[h-1] < ch <= line_index[h] && l == h-1 */
    *line = l;
  }
  if (*line==h-1 && line_index[h]==ch) (*line)++;
  *pos = ch - line_index[*line] + 1;
} 

/*****/

static File_includes root_file = NULL;

static void append_file (File_includes *p, File_includes c)
{ if (*p==NULL) *p = c;
  else append_file (&(*p)->next, c);
}

static void print_includes (File_includes f, int n)
{
  int i;
  if (f==NULL) return;
  for (i=0; i < n; i++) printf ("  ");
  printf ("%s %d..%d\n", IDENT_STRING(f->name), f->begin, f->end);
  print_includes (f->children, i+1);
  print_includes (f->next, i);
}

static int build_file_includes (File_includes cur, int i)
{
  int r;
  Ident f;
  
  do {
    if (i > filenrcnt) return i;

    r = file_index[i].relline;
    f = file_index[i].file_id; 

    if (cur != NULL && f == cur->name) {
      i++;    
    } else if (r==0) {
      /* New include file */
      File_includes inc = malloc (sizeof(*inc));
      inc->name = f;
      inc->next = NULL;
      inc->children = NULL;
      inc->begin = file_index[i].absline;
      if (cur != NULL) {
	append_file (&cur->children, inc);
	inc->end = 0;
      } else {
	root_file = inc;
	inc->end = input_line_nr;
      }
      i = build_file_includes (inc, i+1);
    } else {
      cur->end = file_index[i].absline;
      /* Return to previous include file */
      return i;
    } 
  } while (TRUE);
}

File_includes Build_file_includes (void)
{ 
  if (root_file == NULL) build_file_includes (NULL, 1);
#if 0
  print_includes (root_file, 0);
#endif
  return root_file;
}

void store_line_dir (int rel, Ident f) 
{
  cur_file = f;
  filenrcnt++;
  if (filenrcnt >= file_size) RESIZE (file_index, file_size);
  file_index[filenrcnt].absline = input_line_nr;
  file_index[filenrcnt].relline = rel;
  file_index[filenrcnt].file_id = f;
}

static void find_file_position (int abs, int *rel, Ident *f)
{ int l, h, m;
  if (filenrcnt < 0) {
    *rel = abs;
    *f = cur_file;
    return;
  }
  if (file_index[filenrcnt].absline <= abs) {
    l = filenrcnt; 	/* on or past last line */
  } else {
    l = 0;
    h = filenrcnt;
    while (l < h-1) {
      /* file_index[l].absline <= abs < file_index[h].absline && l < h */
      m = (l+h) / 2; /* l < m < h */
      if (abs < file_index[m].absline) { 
        h = m;
      } else {
        l = m;
      }
    }
    /* file_index[l].absline <= abs < file_index[h].absline && l == h-1 */
  }
  *rel = abs - file_index[l].absline
             + file_index[l].relline;
  *f   = file_index[l].file_id;
}

void _find_location (int ch, int *line, int *pos, Ident *file)
{ int abs;
  if (count_chars) find_position (ch, &abs, pos);
  else abs = ch;
  find_file_position (abs, line, file);
}

void (*find_location) (int ch, int *line, int *pos, Ident *file) = _find_location;
     
int find_line_position (int abs)
{ int line, pos;
  Ident f;
  find_location (abs, &line, &pos, &f);
  return line;
}

Bool Front_local (int ch)
{ int line, pos;
  Ident f;
  find_location (ch, &line, &pos, &f);
  return Front_input_file == f;
}

/*********/

#define GETCHAR \
{ c=(*yy_input)(); input_size++; if (c=='\n') new_input_line(); \
  if (comment) { if (p >= size) RESIZE(comment,size); comment[p++] = c; } \
}

void skip_string (char *end)
{
  NOT_USED(end);
  skip_comment ("");
}

void skip_comment (char *end)
{
  int	c;
  int l = strlen (end);
  int i = 0;
  char *comment = NULL;
  int size = 0;
  int p = 0;
  
  if (count_chars && last_string != NULL) {
    comment = fe_strdup (last_string->string);
    size = strlen(comment);
    p = size;
    if (strcmp (last_string->string, end) == 0) {
      /* Constant comment string */
      input_size += size;
      l = 0;
    }
  }
  
  if (l != 0) GETCHAR;
  do {
    if (l==0) break;
    /* search for '*' */
    if (c != end[i]) i = 0 ;	/* reset i if no match found */
    while((c!=EOF) && (c!=end[i])) GETCHAR;

    if(c==EOF) {
      if ((end[i]=='\12') && (l==(i+1))) break; /* EOF we also interpert as Feed (\012) */ 
      InputError(input_size, TRUE, "missing end-comment");
      break;
    }
    i++;
    if (i==l) break;
    GETCHAR;
  } while (TRUE);
  
  assert (p <= size);
  if (comment) { 
    if (p==size) { comment = realloc (comment, (size+1)*sizeof(comment[0])); }
    comment[p] = 0; last_string->string = comment; 
  }
}
#undef GETCHAR

void update_line_and_fname(char *string)
{
  char *p=string, *q;
  Ident f = cur_file;
  int line = input_line_nr;

  while((*p!='\0') && !isdigit((int)*p)) p++;
  if (*p=='\0') return;

  line = atoi(p);

  while((*p!='\0') && (*p!='\"')) p++;
  
  if (*p!='\0') {
    q = fe_strdup(p + 1);
    p = q;
    while ((*p!='\0') && (*p!='\"')) p++;
    *p = '\0';
    f = Front_Make_identifier (q);
  }
  store_line_dir (line-1, f);
}

/*****/

void record_length (int len)
{ count_chars = TRUE; 
  input_size += len; 
  p_yylloc->first_line = input_size-len;
  p_yylloc->last_line = input_size;
}

void record_symbol (int len, char *text)
{
  NOT_USED(len);
  if (!no_scan_strings) {
    *last_strings = malloc (sizeof(*last_string));
    last_string = *last_strings;
    last_string->pos = p_yylloc->first_line;
    last_string->string = fe_strdup (text);
    last_string->next = NULL;
    last_strings = &last_string->next;
  }
}

/*****/

static Bool is_pre (char *s)
{ if (*s == 0) return FALSE;
  return s[strlen(s)-1] != '\n';
}

static scan_strings 
_gather_comment (scan_strings *s, int pos, Bool pre)
{ scan_strings t = *s;
  if (*s == NULL || (*s)->pos > pos) return NULL;
  if (pretty) {
    if (pre != is_pre((*s)->string)) { 
      return _gather_comment (&(*s)->next, pos, pre);
    }
  } else {
    if (pre && !is_pre((*s)->string)) { 
      return _gather_comment (&(*s)->next, pos, pre);
    }
  }
  *s = t->next;
  t->next = _gather_comment (s, pos, pre);
  return t;
}

scan_strings gather_comment (int pos, Bool pre)
{ return _gather_comment (&first_strings, pos, pre);
}

/*****/

Bool Encode_Bool (char *text)
{ if (strcmp(text,"TRUE" )==0) return TRUE;
  if (strcmp(text,"FALSE")==0) return FALSE;
  if (strcmp(text,"true" )==0) return TRUE;
  if (strcmp(text,"false")==0) return FALSE;
  assert(FALSE);
  return FALSE;
}

Int Encode_Int (char *text)
{ int i = 0;
  assert (sscanf (text, "%d", &i) > 0);
  return i;
}

Int Encode_Oct (char *text)
{ unsigned int i = 0;
  assert (sscanf (text, "%o", &i) > 0);
  return i;
}

Int Encode_Hex (char *text)
{ unsigned int i = 0;
  assert (sscanf (text, "%x", &i) > 0);
  return i;
}

static Bool
is_octal (Char c)
{ return '0' <= c && c <= '7'; }

Char Encode_Char (char *text)
{ Char c = 0;
  unsigned int i;
  c = text[1];
  if (c != '\\') return c;
  switch (text[2]) {
    case 'a' : return '\a';
    case 'b' : return '\b';
    case 'f' : return '\f';
    case 'n' : return '\n';
    case 'r' : return '\r';
    case 't' : return '\t';
    case 'v' : return '\v';    
    default:
      c = 0;
      if (is_octal(text[2])) {
        c = 8*c + text[2] - '0';
	if (is_octal(text[3])) {
          c = 8*c + text[3] - '0';
	    if (is_octal(text[4])) {
              c = 8*c + text[4] - '0';
	    }
	}
	return c;
      } else if (text[2] == 'x') {
        sscanf (&text[3], "%x", &i);
	c = i;
	return c;
      }
      return text[2];
  }
  return c;
}

String Encode_String (char *text)
{ int l = strlen(text);
  String s;

#if 0
  Bool is_str = text[0]=='\"' && text[l-1]=='\"';
  if (is_str) l-=2;
#endif
  
  s = malloc (l+1);
#if 0
  if (is_str) {
    strncpy (s, &text[1], l);
  } else {
    strncpy (s, &text[0], l);
  }
#else
  strncpy (s, &text[0], l);
#endif
  s[l] = 0;
  return s;
}

Ident Encode_Ident (char *text)
{ return Make_identifier (text);
}

Float Encode_Float (char *text)
{ double i;
  assert (sscanf (text, "%lg", &i) > 0);
  return i;
}

void scan_init (char *filename)
{
  if (!line_index) line_index = malloc (line_size*sizeof (line_index[0]));
  if (!file_index) file_index = malloc (file_size*sizeof (file_index[0]));
  Front_input_file = Make_identifier(filename);
  store_line_dir (1, Front_input_file);
}

static char *escape_chars="abfnrtv\'\"\?\\";
static char *escaped_chars="\a\b\f\n\r\t\v\'\"\?\\";

typedef struct string {
  int   len;
  char *string;
} *string;

/* ----------------------------------------------------------------------------
 * Append C to the string S
 */
static string
append_char(string s, char c)
{
  if(!s) {
    s=(string)malloc(sizeof(struct string));
    s->len=0;
    s->string=NULL;
  }
  s->len++;
  s->string = realloc(s->string, s->len);
  s->string[s->len-1]=c;
  return s;
}

/* ----------------------------------------------------------------------------
 * TRUE if S is one of the characters that can be escaped
 */
static Bool
is_escape(char s)
{
  return strchr(escape_chars,s)!=NULL;
}

/* ----------------------------------------------------------------------------
 * 'S' -> '\S'
 */
static char
add_escape(char s)
{
  char *p = strchr(escape_chars,s);
  if(!p) return s;
  return escaped_chars[p-escape_chars];
}

/* ----------------------------------------------------------------------------
 * Get the octal value in *P,  afterward P points to the last character of the
 * value
 */
static unsigned int
oct_value(char **p, Bool *ok)
{
  int k;
  unsigned int v=0;
  char *s=*p;
  
  for(k=0; k<3 && isodigit(*s); k++) {
    v = (v<<3) | (*s-'0');
    s++;
  }
  if(k==0) *ok = FALSE;
  *p=s-1;
  return v;
}

/* ----------------------------------------------------------------------------
 * Get the hexadecimal value in *P+1, (*p should be 'x')
 * afterward P points to the last character of the value
 */
#ifdef hex_value
#undef hex_value
#endif
static unsigned int
hex_value(char **p, Bool *ok)
{
  char *s=*p;
  unsigned int v;

  v=0;
  if(!isxdigit((int)s[1])) {
    *ok = FALSE;
    return v;
  }
  do {
    s++;
    if(isdigit((int)*s))        v = (v<<4) | (*s-'0');
    else if(isxdigit((int)*s))  v = (v<<4) | (tolower(*s)-'a');
  } while(isxdigit((int)s[1]));
  *p=s;
  return v;
}

String
Unescape_String(String s, int *length)
{
  Bool escape=FALSE, ok=TRUE;
  string result=NULL;
  
  while(s[0] && ok) {
    if(!escape && *s=='\\') {
      escape=TRUE;
    } else if(escape) {
      escape=FALSE;
      if(is_escape(*s))     result = append_char(result, add_escape(*s));
      else if(*s=='x')      result = append_char(result, hex_value(&s,&ok));
      else if(isodigit(*s)) result = append_char(result, oct_value(&s,&ok));
      else ok=FALSE;
    } else {
      result = append_char(result, *s);
    }
    s++;
  }
  if(!ok) return NULL;
  *length = result->len;
  append_char(result, 0);
  return result->string;
}
