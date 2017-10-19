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
#ifndef __FLAGS_H
#define __FLAGS_H

#include "doggy.h"

extern Bool search_ops;
extern Bool allow_undeclared_ops;
extern Bool gen_test;
extern Bool tree;
extern Bool ExtraWarnings;
extern char *input_file;
extern char *outfile;
extern char *id_string;

extern void parse_flags (int argc, char **argv);

#endif /* __FLAGS_H */
