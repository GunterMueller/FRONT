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

ifeq "$(UNAME)" "MINGW32"
EXT=.exe
endif

ifeq "$(UNAME)" "CYGWIN_NT-5.0"
EXT=.exe
endif

STATIC = ON

FRONT = $(FRONT_ROOT)/$(UNAME)/bin/Front$(EXT)
DOGGY = $(FRONT_ROOT)/$(UNAME)/bin/doggy$(EXT)
EGG = $(FRONT_ROOT)/$(UNAME)/bin/egg$(EXT)

check-config::
	@ if [ -z "$(FRONT_ROOT)" ]; then $(ECHO) "Error: FRONT_ROOT not set"; false; fi

project/%/_update: $(SRC)/%
	$(MAKE) -f $(ROOT)/Makefile _update "SRC=$(SRC)/$(*D)" "PROJECT=$(*F)" "ROOT=$(SRC)"

_update: $(PROJECTS:%=project/%/_update)
	$(CP) $(FRONT_ROOT)/project/Makefile $(SRC)/Makefile

help:: 
	@ $(ECHO) "  _update          distribute the project/Makefile to the known subdirectories"

include $(FRONT_ROOT)/$(UNAME).mk
