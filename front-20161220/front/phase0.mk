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
PREFIX   = $(FRONT_ROOT)/$(UNAME)
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
	print_lalr.c print_lalr.h  \
	Fonts.h \
	front_end.c front_end.h \
	print_types.c print_types.h \
	flags.c flags.h \
	Checks.c Checks.h \
	highlight.c highlight.h \
	Types.df

DEFS     = -DYYDEBUG=1 -DTEST_ANY -DFRONT2
FRONTFLAGS = -preserve_comment -genpretty -genscope -doggy \
             -multi_start "%"
DOGFLAGS =
DOGPPFLAGS  = -I$(PREFIX)/include -DFRONT2
CPPFLAGS = -DPHASE=0
CFLAGS   = -g -W -Wall -m32

INCLUDES = -I$(PREFIX)/include 

LIBS     = -lpictures -lcpp -lfront -lm
LDFLAGS  = -L$(PREFIX)/lib -m32

ifeq "$(UNAME)" "MINGW32"
LIBS    += -lregex
endif

MY_BOOT     = $(SRC)/boot
BUILD    = $(SRC)/$(UNAME).0
export BUILD
NOCLEAN  = doc CVS

# Boot strap rules
%Print.c %Print.h \
%_parse.c %_parse.h \
%.types %.md \
%.c %.l %.y %.h %_defs.h %_doggy.h \
%_y.c %_y.h %_l.h %_lalr.h %_lalr.c: $(MY_BOOT)/%_parse.c
	@ $(MESSAGE) "Bootstrapping $*.front" || true
	$(CP) $(MY_BOOT)/$*Print.c $(MY_BOOT)/$*Print.h $(MY_BOOT)/$*_parse.c $(MY_BOOT)/$*_parse.h .
	$(CP) $(MY_BOOT)/$*.types $(MY_BOOT)/$*.md .
	$(CP) $(MY_BOOT)/$*.c $(MY_BOOT)/$*.l $(MY_BOOT)/$*.y $(MY_BOOT)/$*.h .
	$(CP) $(MY_BOOT)/$*_defs.h $(MY_BOOT)/$*_doggy.h .
	$(CP) $(MY_BOOT)/$*_y.h $(MY_BOOT)/$*_y.c $(MY_BOOT)/$*_l.c .
	$(CP) $(MY_BOOT)/$*_lalr.h $(MY_BOOT)/$*_lalr.c .

%_doggy.c $(BUILD)/%_doggy.c: $(MY_BOOT)/%_doggy.c
	@ $(MESSAGE) "Bootstrapping $*.df" || true
	$(CP) $(MY_BOOT)/$*_doggy.c .
