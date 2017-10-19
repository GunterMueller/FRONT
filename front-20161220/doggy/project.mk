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
OUT   = doggy$(EXT)

CONFIG_FILES = $(FRONT_ROOT)/Config.mk
PREFIX   = $(FRONT_ROOT)/$(UNAME)
INSTALL  = bin/$(OUT)
FILES = main.c \
	Types.c Types.h \
	Checks.c Checks.h \
	GenCode.c GenCode.h  \
	doggy.front \
	flags.c flags.h

DEFS     = -DDOGGY -DYYDEBUG=1
FRONTFLAGS = -preserve-comment -genpretty
DOGFLAGS =
DOGPPFLAGS  =
CPPFLAGS =
CFLAGS   = -g -W -Wall -m32

INCLUDES =  -I$(FRONT_ROOT)/$(UNAME)/include 
LIBS     = -lfront -lm
LDFLAGS  = -L$(FRONT_ROOT)/$(UNAME)/lib -m32

BUILD    = $(SRC)/$(UNAME)
NOCLEAN  = doc CVS
