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
RESULT     = library

REQUIRES = $(FRONT_ROOT)/libfront/project.mk

PROJECTS   = 

# The filename of the output
OUT        = libegg.a

CONFIG_FILES = $(FRONT_ROOT)/Config.mk
LIBADD     =

# Where everything will be installed
PREFIX   = $(FRONT_ROOT)/$(UNAME)
INCLUDE_PREFIX = $(PREFIX)/include/egg

# What will be installed, and where.
# can be. bin/aap, lib/libnoot.a include/mies.h
INSTALL    = lib/$(OUT) include/egg_msg.h

# _All_ files in the project.
FILES      =  egg_msg.c egg_msg.h

FRONTFLAGS = -genscope -genprint -genpretty -w -multi_start "%"
DEFS     = 
INCLUDES = -I$(PREFIX)/include
CPPFLAGS = 
CFLAGS   = -g -W -Wall -m32
LIBS     = -lfront -lct 
LDFLAGS  = -L$(PREFIX)/lib -m32

BUILD    = $(SRC)/$(UNAME)
NOCLEAN  = CVS
FRONT_ROOT  = $(SRC)/..
