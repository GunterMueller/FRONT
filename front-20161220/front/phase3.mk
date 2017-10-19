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

CONFIG_FILES = $(FRONT_ROOT)/Config.mk

BUILD    = $(SRC)/$(UNAME).2
NOCLEAN  = doc CVS Makefile.old
MY_BOOT     = $(SRC)/boot
DEFAULT  = $(BUILD)/$(BUILD_MAKEFILE) build/myboot
PREFIX   = $(SRC)/$(UNAME)

MY_BOOTFILES = $(patsubst %, $(MY_BOOT)/%, $(wildcard *.c *.h *.y *.l *.types *.md))

do-myboot: $(MY_BOOTFILES)

$(MY_BOOT)/% : $(BUILD)/%
	@ $(MESSAGE) "Updating $*" || true
	$(CP) $< $@
