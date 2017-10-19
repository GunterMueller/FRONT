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
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "text.h"
#include "mem.h"
#include "error.h"
#include "egg_msg.h"

static int exit_val = 1;
static egg_msg all_messages = NULL;
static egg_msg printed_messages = NULL;

static int has_been_printed(egg_msg me);
static void egg_std_printer(char *text);
static void (*egg_print_message)(char *text) = egg_std_printer;

/* ----------------------------------------------------------------------------
 * Create a new egg message
 */
static egg_msg
new_egg(void)
{
  egg_msg me = fe_malloc (sizeof (*me));
  me->key = -1;
  me->kind = egg_disabled_kind;
  me->msg = NULL;
  me->withdrawn = 0;
  me->next = NULL;
  me->fix = NULL;
  me->object = NULL;
  return me;
}

/* ----------------------------------------------------------------------------
 * Get the message in M, create one if not there
 */
static egg_msg
get_msg (egg_msg *m)
{
  if (!*m) *m = new_egg ();
  return *m;
}

/* ----------------------------------------------------------------------------
 * TRUE if ther are errors
 */
int
egg_has_errors(void)
{
  egg_msg msg;
  int fatal = 0;

  for (msg = all_messages; msg; msg = msg->next) {
    if (msg->kind != egg_disabled_kind) {
      if (msg->key<0 || msg->kind==egg_error_kind)  fatal = 1;
    }
  }
  return fatal;
}

/* ----------------------------------------------------------------------------
 * Print the messages to standard error
 */
static void
egg_std_printer(char *text)
{
  fprintf(stderr, "%s", text);
}

void
egg_set_printer( void (*printer)(char *text) )
{
  egg_print_message = printer;
}

void
egg_reset_printer()
{
  egg_print_message = egg_std_printer; 
}

void
egg_set_exit_value(int v)
{ exit_val = v; }

int
egg_print_messages(void)
{
  int internal_errors=0;
  egg_msg msg, last;
  int fatal = egg_disabled_kind;

  if (!all_messages) return fatal;  
  for (msg = all_messages; msg; msg = msg->next) {
    last = msg;
    if (msg->kind != egg_disabled_kind) {
      if (msg->key<0) internal_errors = 1;
      if ( !has_been_printed(msg) ) 
        egg_print_message(msg->msg);
      if (msg->kind==egg_error_kind) fatal = egg_error_kind;
    }
  }
  assert (!internal_errors);

  last->next = printed_messages;
  printed_messages = all_messages;
  
  all_messages = NULL;
  return fatal==egg_error_kind;
}

/* ----------------------------------------------------------------------------
 * Fix the errors using their FIX function
 */
void
egg_fix_errors(void)
{
  egg_msg prev =NULL, msg, next;

  for (msg = all_messages; msg; msg = next) {
    next = msg->next;
    if (msg->fix && msg->fix (msg->object)) {
      msg->withdrawn = 1;
      if (prev) prev->next = msg->next;
      else      all_messages = msg->next;
    } else {
      msg->fix = NULL;
      prev = msg;
    }
  }
}

/* ----------------------------------------------------------------------------
 * Withdraw all messages
 */
void
egg_withdraw_all (void)
{
  while(all_messages) egg_withdraw(all_messages);
}

/* ----------------------------------------------------------------------------
 * Print the messages to standard error, if any is fatal, exit(1)
 */
void
egg_exit_on_errors(void)
{
  if (egg_print_messages ()) exit (exit_val);
}


/* ----------------------------------------------------------------------------
 * Abort when there are errors
 */
void
egg_abort_on_errors (void)
{
  if (!egg_has_errors()) return;
  egg_print_messages();
  abort();
}

/* ----------------------------------------------------------------------------
 * Add a message
 */
egg_msg
egg_submit (egg_msg me) 
{  
  egg_msg msg;

  for (msg = all_messages; msg && msg->next; msg = msg->next) {
    if (msg->next->key > me->key) break;
  }
  if (!msg) all_messages = me;
  else {
    if (!msg->fix && !me->fix) {
      if (strcmp (msg->msg, me->msg)==0) return msg;
    } else if (msg->fix==me->fix && msg->object==me->object && msg->object) {
      return msg;
    }
    me->next = msg->next;
    msg->next = me;
  }
  return me;
}

static int 
has_been_printed(egg_msg me)
{
  egg_msg msg = printed_messages;
  for (; msg; msg = msg->next) {
    if ( msg->key == me->key && strcmp(msg->msg, me->msg)==0 ) 
      return 1;
  }
  return 0; 
}

/* ----------------------------------------------------------------------------
 * Remove a message
 */
void
egg_withdraw (egg_msg me)
{
  egg_msg msg;

  if (!me) return;
  assert (all_messages);
  me->withdrawn = 1;
  if (me==all_messages) {
    all_messages = me->next;
    return;
  }
    
  for (msg = all_messages; msg->next; msg = msg->next) {
    if (msg->next == me) break;
  }
  assert (msg->next);
  msg->next = me->next;
}

/* ----------------------------------------------------------------------------
 * Append the textual representation of V to MSG
 */
static char *
decimal (char *msg, int v)
{
  char *revnum = NULL;
  char numbers[]="0123456789";
  
  if (v==0) return fe_charappend (msg, '0');
  else if (v<0) {
    msg = fe_charappend (msg, '-');
    v = -v;
  }
  while (v) {
    int d = v%10;
    revnum = fe_charappend (revnum, numbers[d]);
    v /= 10;
  }
  return fe_strappend (msg, fe_strrev (revnum));
}

/* ----------------------------------------------------------------------------
 * Append the formatted FMT to MSG
 */
static void
vformat (char **dst, char *fmt, va_list args)
{
  int arg = 0;
  int i,j;

  for (i=j=0; fmt[i]; i++) {
    if (!arg) {
      arg = fmt[i]=='%';
    } else {
      int l = 0;
      *dst = fe_strnappend(*dst, &fmt[j], i-j-1);
      j = i+1;
      if (fmt[i]=='l') {
        l = 1;
	i++;
      }
      switch (fmt[i]) {
      case 's': *dst = fe_strappend (*dst, va_arg (args, char*)); break;
      case 'd': if (l) *dst = decimal (*dst, va_arg (args, long long)); 
                else   *dst = decimal (*dst, va_arg (args, int)); 
		break;
      case '%': j--; break;
      default:
        fe_abort ("unsupported format specifier");
      }
      arg= 0;
    }
  }
  *dst = fe_strnappend(*dst, &fmt[j], i-j);
}

void
egg_vadd_format (egg_msg *m, char *fmt, va_list args)
{
  egg_msg me = get_msg (m);
  vformat (&me->msg, fmt, args);
}

void
egg_add_string (egg_msg *m, char *s)
{
  egg_msg me = get_msg (m);
  me->msg = fe_strappend (me->msg, s);
}

void
egg_sort_key (egg_msg *m, int key)
{
  egg_msg me = get_msg (m);
  me->key = key;
  if (me->key<0) egg_add_string (m, "(internal error):");
}

void
egg_set_kind (egg_msg *m, egg_msg_kind kind)
{
  egg_msg me = get_msg (m);
  me->kind = kind;
}


void
egg_set_fix (egg_msg *m, int (*fix)(void*), void *object)
{
  egg_msg me;
  if (fix) {
    me = get_msg (m);
    me->fix = fix;
    me->object = object;
  }
}

const char *
egg_msg_name (egg_msg_kind k)
{
  switch (k) {
  case egg_disabled_kind: return "disabled";
  case egg_warning_kind:  return "warning";
  case egg_error_kind:    return "error";
  }
  fe_abort ("unexpected message kind");
  return 0;
}
