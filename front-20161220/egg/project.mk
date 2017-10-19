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

# RESULT determines what will be built, set to library or binary
RESULT     = binary

PROJECTS   = 

# The filename of the output
OUT        = egg$(EXT)

CONFIG_FILES = $(FRONT_ROOT)/Config.mk
LIBADD     = 

BOOT = boot

# Where everything will be installed
PREFIX   = $(FRONT_ROOT)/$(UNAME)

# What will be installed, and where.
# can be. bin/aap, lib/libnoot.a include/mies.h
INSTALL    = bin/$(OUT)

# _All_ files in the project.
FILES      =  egg.front \
              main.c \
              init.c init.h \
              messenger.c messenger.h

FRONTFLAGS = -genpretty -w -multi-start "%"
DEFS     = 
INCLUDES = -I$(PREFIX)/include
CPPFLAGS = 
CFLAGS   = -g -W -Wall -m32

LIBS     = -lfront  -lm
LDFLAGS  = -L$(PREFIX)/lib -m32

ifeq "$(UNAME)" "MINGW32"
LIBS     += -lregex
endif

BUILD    = $(SRC)/$(UNAME)
NOCLEAN  = CVS
FRONT_ROOT  = $(SRC)/..
