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

#ifndef _cpp_error_h
#define _cpp_error_h

#include <stdarg.h>
#include "token.h"

extern int Success;

void cpp_vsyntax (token t, char *msg, va_list args);
void cpp_syntax (token t, char *msg, ...);
void cpp_vwarning (token t, char *msg, va_list args);
void cpp_warning (token t, char *msg, ...);

#endif /* _cpp_error_h */
