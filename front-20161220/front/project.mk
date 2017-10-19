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
PROJECTS = phase0.mk phase1.mk phase2.mk phase3.mk

INSTALL = bin/Front$(EXT)

PREFIX = $(FRONT_ROOT)/$(UNAME)

CONFIG_FILES = $(FRONT_ROOT)/Config.mk

NOCLEAN  = doc CVS Makefile.old

BUILD = $(SRC)/$(UNAME)
DEFAULT = phase1

phase0: project/phase0.mk

phase0-install: phase0 project/phase0.mk/install

phase1: project/phase1.mk

phase2: phase1 project/phase2.mk phase2-message project/phase3.mk

phase2-install: phase2 project/phase2.mk/install shallow-install

phase2-message:
	@ $(MESSAGE) "Self generation successful" || true
