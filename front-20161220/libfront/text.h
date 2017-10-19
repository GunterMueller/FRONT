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
#ifndef _text_h
#define _text_h

#include <stdlib.h>
#include <stdarg.h>

/* Duplicate string S */
char *
fe_strdup(const char *s);

/* Duplicate LEN character of string S */
char *
fe_strndup(const char *s, size_t len);

/* Reverse the string S (in place) */
char *
fe_strrev(char *s);

/* Reverse the first LEN characters of S (in place) */
char *
fe_strnrev(char *s, size_t len);

/* Duplicate a substring of string S, START and END indicate the range of
 * characters.   substr("abcdef",1,4) = "bcde". Negative indices start from
 * the end: substr("abcdef",-3,-1) = "def."
 */
char *
fe_substr(const char *s, int start, int end);

/* Length of string S, or 0 if S=NULL */
int
fe_strlen(const char *s);

/* Create a new string containing the concatenation of S1 and S2 */
char *
fe_strcat(const char *s1, const char *s2);

/* Append string S2 to S1, This reallocates S1 */
char *
fe_strappend(char *s1, const char *s2);

/* Append LEN characters of S2 to S1, This reallocates S1 */
char *
fe_strnappend (char *s1, const char *s2, size_t len);

/* Append char C to S, This reallocates S */
char *
fe_charappend(char *s, char c);

/* Prepend string S1 to S2, This reallocates S2 */
char *
fe_strprepend(const char *s1, char *s2);

/* Replace all characters in STR that are not in SET by REPL */
char *
fe_strset (char *str, char *set, char repl);

/* Replace all characters in STR that are also in SET by REPL */
char *
fe_strcset (char *str, char *set, char repl);


/* Replace substring in S at offset OFFS of length LEN with copy of REPLACEMENT,
 * reallocating S if needed. Return number of characters added to S (negative if deleted).
 */
int fe_strreplace (char **s, unsigned int offs, unsigned int len, char *replacement);

/* find at most N occurences of FIND in S and replace LEN characters by a copy
 * of the string returned by user supplied function REPLACE, reallocating S if needed.
 * The user supplied function gets a pointer into S where a match was found together
 * with the supplied LEN.
 * Returns how many replacements took place. The string replaced is not 
 * searched again for occurences of FIND.
 */
int fe_strfindreplace (char **s, char *find, unsigned int len,
		       char *(*replacement)(char *, unsigned int), unsigned int n);

/* find at most N occurences of FIND in S and replace by string REPLACEMENT,
 * reallocating S if needed. Returns how many replacements took place.
 */
int fe_strfindreplacestr (char **s, char *find, char *replacement, unsigned int n);

/* return whether s is a suffix of t */
int
fe_issuffix(char *s, char *t);

/* return whether s is a prefix of t */
int
fe_isprefix(char *s, char *t);

/* Returns the length of the common prefix of s and t */
size_t fe_strprefix (char *s, char *t);

/* Returns the length of the common suffix of s and t */
size_t fe_strsuffix (char *s, char *t);

/* printf to a string, the string must be freed by the caller */
char *fe_asprintf (char *fmt, ...);
char *fe_vasprintf (char *fmt, va_list args);

#endif /*_text_h */
