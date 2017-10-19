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
#include <string.h>
#include <stdlib.h>
#include "mem.h"
#include "text.h"
#include "book.h"

/* ----------------------------------------------------------------------------
 * Duplicate string S
 */
char *
fe_strdup(const char *s)
{
  char *result;
  if(!s) return NULL;
  result=fe_malloc(strlen(s)+1);
  strcpy(result,s);
  return result;
}

/* ----------------------------------------------------------------------------
 * Duplicate LEN characters of string S, result will always have LEN bytes
 * allocated.
 */
char *
fe_strndup(const char *s, size_t len)
{
  char *result;
  if(!s) return NULL;
  result=fe_malloc(len+1);
  strncpy(result,s,len);
  result[len]=0;
  return result;
}

/* ----------------------------------------------------------------------------
 * Reverse the first LEN bytes in S
 */
char *
fe_strnrev(char *s, size_t len)
{
  int l = len - 1;
  int i;

  for(i=0; i<l; i++, l--) {
    char d = s[i];
    s[i] = s[l];
    s[l] = d;
  }
  return s;
}

/* ----------------------------------------------------------------------------
 * Reverse the string S
 */
char *
fe_strrev(char *s)
{
  return fe_strnrev (s, fe_strlen (s));
}

/* ----------------------------------------------------------------------------
 * Duplicate a substring of string S, START and END indicate the range of
 * characters.   substr("abcdef",1,4) = "bcde". Negative indices start from
 * the end: substr("abcdef",-3,-1) = "def."
 */
char *
fe_substr(const char *s, int start, int end)
{
  if(!s) return NULL;
  if(start<0) start = strlen(s)+start+1;
  if(end<0)   end = strlen(s)+end+1;
  if(end<start) return NULL;
  return fe_strndup(s+start,end-start);
}

/* ----------------------------------------------------------------------------
 * The length of string S, or 0 if S is NULL
 */
int
fe_strlen(const char *s)
{
  return s ? strlen(s) : 0;
}

/* ----------------------------------------------------------------------------
 * Create a new string containing the concatenation of S1 and S2
 */
char *
fe_strcat(const char *s1, const char *s2)
{
  char *result=fe_strdup(s1);
  return fe_strappend(result,s2);
}

/* ----------------------------------------------------------------------------
 * Append string S2 to S1, This reallocates S1.
 */
char *
fe_strappend (char *s1, const char *s2)
{
  if(!s1) return fe_strdup(s2);
  if(!s2) return s1;
  s1 = fe_realloc (s1, fe_strlen (s1) + fe_strlen (s2) + 1);
  return strcat (s1, s2);
}

/* ----------------------------------------------------------------------------
 * Append string LEN characters of S2 to S1, This reallocates S1.
 */
char *
fe_strnappend (char *s1, const char *s2, size_t len)
{
  size_t s2len, s1len;
  
  if(!s1) return fe_strndup(s2, len);
  if(!s2) return s1;
  s2len = fe_strlen (s2);
  s1len = fe_strlen (s1);
  if (len > s2len) len = s2len;
  s1 = fe_realloc (s1, s1len + len + 1);
  s1 = strncat (s1, s2, len);
  s1 [s1len + len] = 0;
  return s1;
}

/* ----------------------------------------------------------------------------
 * Append char C to S, This reallocates S.
 */
char *
fe_charappend(char *s, char c)
{
  char s2[2];

  s2[0] = c;
  s2[1] = 0;
  return fe_strappend(s, s2);
}

/* ----------------------------------------------------------------------------
 * Prepend string S1 to S2, This reallocates S2.
 */
char *
fe_strprepend(const char *s1, char *s2)
{
  if(!s2) return fe_strdup(s1);
  if(!s1) return s2;
  s2=fe_realloc(s2, fe_strlen(s1)+fe_strlen(s2)+1);
  memmove(s2+fe_strlen(s1), s2, fe_strlen(s2)+1);
  memcpy(s2, s1, fe_strlen(s1));
  return s2;
}

/*------------------------------------------------------------------------------
 * Replace substring in S at offset OFFS of length LEN with copy of REPLACEMENT,
 * reallocating S if needed. Return number of characters added to S (negative if deleted).
 */
int fe_strreplace (char **s, unsigned int offs, unsigned int len, char *replacement)
{
  unsigned int sLen, replacementLen, tail;
  char *copy;
  int added;

  if (!s || !replacement) return 0;

  sLen = fe_strlen (*s);

  if (offs >= sLen) return 0;
  
  tail = offs + len;

  if (tail > sLen) return 0;

  replacementLen = fe_strlen (replacement);
  
  added = replacementLen - len;

  /* be careful about 's' and 'replacement' pointing into the same 0-terminated region */
  if (added) {

    copy = fe_malloc (sLen + added + 1);

    /* front */
    if (offs) memcpy (copy, *s, offs);
    /* replacement */
    memcpy (copy + offs, replacement, replacementLen);
    /* tail including final 0 */
    strcpy (copy + offs + replacementLen, *s + tail);

    fe_free (*s);
    *s = copy;

  } else {

    /* replacement */
    memmove (*s, replacement, replacementLen);
    
  }

  return added;
}

/*------------------------------------------------------------------------------
 * find at most N occurences of FIND in S and replace LEN characters by a copy
 * of the string returned by user supplied function REPLACE, reallocating S if needed.
 * The user supplied function gets a pointer into S where a match was found together
 * with the supplied LEN.
 * Returns how many replacements took place. The string replaced is not 
 * searched again for occurences of FIND.
 */

int fe_strfindreplace (char **s, char *find, unsigned int len,
		       char *(*replacement)(char *, unsigned int), unsigned int n)
{
  unsigned int replacements = 0;
  int offset;

  if (!s || !*s || !find || !len || !replacement) return 0;

  offset = 0;
  while (replacements < n && (offset = strstr (*s + offset, find) - *s) >= 0) {
    offset += len + fe_strreplace (s, offset, len, replacement (*s + offset, len));
    replacements++;
  }

  return (int)replacements;
}

/*------------------------------------------------------------------------------
 * find at most N occurences of FIND in S and replace by string, reallocating S
 * if needed. Returns how many replacements took place.
 */
static char *fixed;
static char *fixedstr (char *s, unsigned int l) {
  NOT_USED(s); 
  NOT_USED(l); 
  return fixed; 
}

int fe_strfindreplacestr (char **s, char *find, char *replacement, unsigned int n)
{
  fixed = replacement;
  return fe_strfindreplace (s, find, fe_strlen (find), fixedstr, n);
}

/* ----------------------------------------------------------------------------
 * Replace all characters in STR that are not in SET by REPL
 */
char *
fe_strset (char *str, char *set, char repl)
{
  int i;
  
  for (i=0; str[i]; i++) {
    if (!strchr (set, str[i])) {
      str[i] = repl;
    }
  }
  return str;
}

/* ----------------------------------------------------------------------------
 * Replace all characters in STR that are also in SET by REPL
 */
char *
fe_strcset (char *str, char *set, char repl)
{
  int i;
  
  for (i=0; str[i]; i++) {
    if (strchr (set, str[i])) {
      str[i] = repl;
    }
  }
  return str;
}

/*------------------------------------------------------------------------------
 * return whether s is a suffix of t
 */
int
fe_issuffix(char *s, char *t)
{
  if (fe_strlen(s) == 0) return 1;
  if (fe_strlen(s) > fe_strlen(t)) return 0;
  return strcmp(s, t+fe_strlen(t)-fe_strlen(s)) == 0;
}

/*------------------------------------------------------------------------------
 * return whether s is a prefix of t
 */
int
fe_isprefix(char *s, char *t)
{
  return strstr(t, s) == t;
}


/* Returns the length of the common prefix of s and t */
size_t fe_strprefix (char *s, char *t)
{
  size_t l = 0;
  for (; s[l] && t[l] && s[l] == t[l]; l++);
  return l;
}

/* Returns the length of the common suffix of s and t */
size_t fe_strsuffix (char *s, char *t)
{
  int ls = strlen(s)-1, lt=strlen(t)-1;
  size_t i=0;
  for (; ls>=0 && lt>=0 && s[ls] == t[lt]; i++,ls--,lt--);
  return i;
}

char *
fe_vasprintf (char *fmt, va_list args)
{
  fe_book_t *book = fe_book_start ();
  char *s;
  fe_book_vprintf (book, fmt, args);
  s = fe_book_to_string (book);
  fe_book_free (book);
  return s;
}

char *
fe_asprintf (char *fmt, ...)
{
  va_list args;
  char *s;
  
  va_start (args, fmt);
  s = fe_vasprintf (fmt, args);
  va_end (args);
  return s;
}
