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
#ifndef _egg_msg_h
#define _egg_msg_h

typedef struct s_egg_msg *egg_msg;

#include <stdarg.h>

typedef enum {
  egg_disabled_kind,
  egg_warning_kind,
  egg_error_kind,
} egg_msg_kind;

struct s_egg_msg {
  int   key;
  egg_msg_kind kind;
  char *msg;
  int   withdrawn;
  egg_msg next;
  void *object;
  int (*fix)(void*);
};

void egg_exit_on_errors(void);
void egg_abort_on_errors (void);

int egg_has_errors(void);
int egg_print_messages(void);
void egg_fix_errors(void);
void egg_withdraw_all (void);

egg_msg egg_submit (egg_msg m);
void egg_withdraw (egg_msg me);
void egg_vadd_format (egg_msg *m, char *fmt, va_list args);
void egg_add_string (egg_msg *m, char *s);
void egg_sort_key (egg_msg *m, int key);
void egg_set_kind (egg_msg *m, egg_msg_kind kind);
void egg_set_fix (egg_msg *m, int (*fix)(void*), void *object);
const char *egg_msg_name (egg_msg_kind k);

void egg_set_printer( void (*printer)(char *text) );
void egg_reset_printer();
void egg_set_exit_value(int v);

#endif /* _egg_msg_h */
