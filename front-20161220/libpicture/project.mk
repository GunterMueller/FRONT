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
OUT   = libpictures.a

CONFIG_FILES = $(FRONT_ROOT)/Config.mk

PREFIX   = $(FRONT_ROOT)/$(UNAME)
INCLUDE_PREFIX     = $(PREFIX)/include/pictures

INSTALL  = lib/$(OUT) \
	   include/Picture.h \
	   include/Pictures.h \
	   include/Pictures_parse.h \
	   include/Pictures_defs.h 

FILES = Pictures.front \
	Fonts.h  \
	Picture.h Picture.c

DEFS     = -DDOGGY -DYYDEBUG=1 -DTEST_ANY
FRONTFLAGS = -preserve-comment -genpretty -doggy \
             -multi-start "%" -back-end-hooks
CPPFLAGS =
CFLAGS   = -g -W -Wall -m32

INCLUDES =  -I$(FRONT_ROOT)/$(UNAME)/include

BOOT     = boot
BUILD    = $(SRC)/$(UNAME).0
NOCLEAN  = doc CVS 
