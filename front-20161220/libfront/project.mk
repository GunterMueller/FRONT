### Copyright (C) 2000-2005 Philips Electronics N.V.
### 
### This library is free software; you can redistribute it and/or
### modify it under the terms of the GNU Lesser General Public
### License as published by the Free Software Foundation; either
### version 2.1 of the License, or (at your option) any later version.
### 
### This library is distributed in the hope that it will be useful,
### but WITHOUT ANY WARRANTY; without even the implied warranty of
### MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
### Lesser General Public License for more details.
### 
### You should have received a copy of the GNU Lesser General Public
### License along with this library; if not, write to the Free Software
### Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
RESULT = library

OUT   = libfront.a

CONFIG_FILES = $(FRONT_ROOT)/Config.mk

PREFIX   = $(FRONT_ROOT)/$(UNAME)
PREFIX_include = $(PREFIX)/include/front

INSTALL  = lib/$(OUT) \
           include/Basic.types \
	   include/Basic.md \
           $(FILES:%.h=include/%.h)

FILES = SymTab.c SymTab.h \
	basic_types.c basic_types.h \
	old_error.c old_error.h \
	front_list.c front_list.h \
	hash.c hash.h \
	print_support.c print_support.h \
	scan_support.c scan_support.h \
	parse_support.c parse_support.h \
	dump_support.c dump_support.h \
	support.c support.h \
	ast_remove.c ast_remove.h \
	ast_replace.c ast_replace.h \
	ast_error.c ast_error.h \
        \
        book.h \
        book_core.c book_core.h \
        book_print.c book_print.h \
        \
        error.c error.h \
        filename.c filename.h \
	flags.c flags.h \
	mem.c mem.h \
	text.c text.h \
        shortest.c shortest.h \
	strconcom.c strconcom.h \
	sort.c sort.h \
	mempool.c mempool.h \
	skiplist.c skiplist.h \
	bitset.c bitset.h \
        egg_msg.c egg_msg.h

DEFS     = 
INCLUDES =  -I$(PREFIX)/include 
CPPFLAGS =
CFLAGS   = -g -W -Wall -m32

LIBS     = 
LDFLAGS  =  -m32

BUILD    = $(SRC)/$(UNAME)
NOCLEAN  = CVS
