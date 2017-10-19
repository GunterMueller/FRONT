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

# RESULT determines what will be built, set to library, sharedlib, or binary
RESULT     = 

# Sub projects to build, this is a list of project files (like this one)
PROJECTS   = libfront/project.mk \
	     libpicture/project.mk \
	     front/phase0.mk \
	     egg/project.mk \
	     doggy/project.mk \
	     cpp/project.mk 


# The filename of the output
OUT        = 

# List of make configuration files
CONFIG_FILES = $(FRONT_ROOT)/Config.mk

# If RESULT=library, instead of creating a new library, add to this one
LIBADD     =

# Where everything will be installed
PREFIX     = $(FRONT_ROOT)/$(UNAME)

# What will be installed, and where.
# can be. bin/aap, lib/libnoot.a include/mies.h
INSTALL    = 

# _All_ files in the project.
# C++ files have the extension ".cc" or ".C"
FILES      = 

# -D flags for the C preprocessor
DEFS       =

# -I flags for the C preprocessor
INCLUDES   =

# Flags for Front
FRONTFLAGS =

# Flags for doggy
DOGFLAGS   =

# Preprocessor flags for doggy
DOGPPFLAGS =

# C preprocessor flags
CPPFLAGS   =

# C compilation flags
CFLAGS     = -g -W -Wall -m32

# C++ compilation flags
CXXFLAGS     = -g -W -Wall

# Libraries to link with
LIBS       =

# Linker flags
LDFLAGS    = -m32

# Where to build everything
BUILD      = $(SRC)/$(UNAME)

# These are not removed on a distclean
NOCLEAN    = CVS CVSROOT Config.mk

# Make targets:
#   make all       - builds $(OUT)
#   make clean     - removes all files generated during a "make all"
#   make distclean - removes all files except $(FILES), $(NOCLEAN), project.mk
#                    and the makefile
#   make install   - installs the files mentioned in $(INSTALL) in the $(PREFIX)
#                    directory, currently the makefile can only install in
#                    $(PREFIX)/bin, $(PREFIX)/lib, and $(PREFIX)/include
#   make uninstall - removed  the files mentioned in $(INSTALL) from $(PREFIX)
export FRONT_ROOT = $(SRC)

