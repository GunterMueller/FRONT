### Copyright (C) 2000-2005 Philips Electronics N.V.
### 
### This program is free software; you can redistribute it and/or
### modify it under the terms of the GNU General Public License
### as published by the Free Software Foundation; either version 2
### of the License, or (at your option) any later version.
###
### This program is distributed in the hope that it will be useful,
### but WITHOUT ANY WARRANTY; without even the implied warranty of
### MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
### GNU General Public License for more details.
###
### You should have received a copy of the GNU General Public License
### along with this program; if not, write to the Free Software
### Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
### 
RESULT = binary
OUT   = Front$(EXT)
PROJECTS = 

REQUIRES = $(FRONT_ROOT)/cpp/project.mk

CONFIG_FILES = $(FRONT_ROOT)/Config.mk
PREFIX   = $(SRC)/$(UNAME)
BIN_PREFIX = $(PREFIX)
INSTALL  = bin/$(OUT)
FILES = \
	front.front \
	Types.front \
	grammar.front \
	Lalr.front \
	main.c \
	GenCode.c GenCode.h  \
	GenTypes.c GenTypes.h  \
	GenSubParse.c GenSubParse.h  \
	GenLex.c GenLex.h  \
	GenGrammar.c GenGrammar.h  \
	GenDoggy.c GenDoggy.h  \
	GenPrint.c GenPrint.h  \
	GenDump.c GenDump.h  \
	GenBdump.c GenBdump.h  \
	GenDiagrams.c GenDiagrams.h  \
	GenLalr.c GenLalr.h  \
	print_lalr.c print_lalr.h \
	front_end.c front_end.h \
	print_types.c print_types.h \
	flags.c flags.h \
	Checks.c Checks.h \
	highlight.c highlight.h \
	Types.df

DEFS     = -DYYDEBUG=1 -DTEST_ANY -DFRONT2
#DEFS     = -DYYDEBUG=1 -DTEST_ANY 
FRONTFLAGS = -preserve-comment -genpretty -doggy \
             -multi-start "%"
DOGFLAGS =
DOGPPFLAGS  = -I$(FRONT_ROOT)/$(UNAME)/include -DFRONT2
#DOGPPFLAGS  = -I$(FRONT_ROOT)/$(UNAME)/include
CPPFLAGS =
CFLAGS   = -g -W -Wall -DPHASE=1 -m32

INCLUDES = -I$(PREFIX)/include -I$(FRONT_ROOT)/$(UNAME)/include
LIBS     = -lpictures -lcpp -lfront -lm
ifeq "$(UNAME)" "MINGW32"
LIBS += -lregex
endif

LDFLAGS  = -L$(PREFIX)/lib -L$(FRONT_ROOT)/$(UNAME)/lib -m32

BUILD    = $(SRC)/$(UNAME).1
NOCLEAN  = doc CVS

override FRONT = $(SRC)/$(UNAME).0/Front
