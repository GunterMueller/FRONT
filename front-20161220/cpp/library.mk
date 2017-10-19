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

# RESULT determines what will be built, set to library or binary
RESULT     = library

PROJECTS   = 

# The filename of the output
OUT        = libcpp.a

CONFIG_FILES = $(FRONT_ROOT)/Config.mk
LIBADD     = 

# Where everything will be installed
PREFIX   = $(FRONT_ROOT)/$(UNAME)

# What will be installed, and where.
# can be. bin/aap, lib/libnoot.a include/mies.h
INSTALL    = lib/$(OUT) \
	     include/cpp.h

# _All_ files in the project.
FILES      =  cpp.c cpp.h \
	      pp.c pp.h \
	      token.c token.h \
	      file.c file.h \
	      sequence.c sequence.h \
	      define.c define.h \
	      emit.c emit.h \
	      cpp.l expression.y \
              errors.egg

DEFS     =
INCLUDES = -I$(PREFIX)/include -I$(FRONT_ROOT)/$(UNAME)/include
CPPFLAGS = 
CFLAGS   = -g -W -Wall -m32
LIBS     = 
LDFLAGS  = -m32
EGGFLAGS = -P cpp_ 
BUILD    = $(SRC)/$(UNAME)
NOCLEAN  = CVS
FRONT_ROOT  = $(SRC)/..
