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

### Various variables, don't change unless you REALLY know what you're doing,
### You shouldn't need to change this.
### ----------------------------------------------------------------------------

### Name of the Makefile in the source directory
MAKEFILE = Makefile

### Name of the Makefile in the build directory
BUILD_MAKEFILE = $(PROJECT:%.mk=%.makefile)

### Name of the Makefile used for make install
INSTALL_MAKEFILE = $(BUILD)/install.$(PROJECT)

### Name of the host platform
ifndef UNAME
export UNAME = $(shell uname -s)
endif

### Directory where sources can be found
SRCDIR = $(SRC)

### Directory where make will be run
SRC = $(_CURDIR)

### Directory where intermediate files will be stored
BUILD = $(SRC)/$(UNAME)

### Directory of the top level project
ROOT = $(_CURDIR)

### SRC relative to ROOT
RELSRC = $(subst $(ROOT)/,,$(SRC)/)

### Tag of the entire build run
ifndef TAG
TAG := $(shell echo $$$$)
export TAG
endif

### Default project file name
PROJECT = project.mk

### Which target to build on "make all"
DEFAULT = build/all

### Directory where make was invoked
# GNU make < 3.79.1 doesn't automatically set CURDIR, use PWD by default
ifeq "$(CURDIR)" ""
CURDIR := $(shell pwd)
export CURDIR
endif

# PvL : on MingW strip driveletter and ':' from CURDIR path to avoid 'multiple target patterns' error.
#       in the makefile, now use _CURDIR instead of CURDIR.
#
ifeq "$(UNAME)" "MINGW32"
_CURDIR = $(if $(findstring :,$(CURDIR)),$(word 2,$(subst :, ,$(CURDIR))),$(CURDIR))
else
_CURDIR = $(CURDIR)
endif

### Install categories.
###   for each category <cat> we have
###   - PREFIX_<cat>  as install directory, default $(PREFIX)/<cat>
###   - INSTALL_<cat> contains the files to install
###   In the INSTALL variable the files <cat>/file.name are considered
###   as beloning to INSTALL_cat>
INSTALL_CATEGORIES = doc bin lib include

### The following are for backwards compatability
PREFIX_doc = $(DOC_PREFIX)
PREFIX_bin = $(BIN_PREFIX)
PREFIX_lib = $(LIB_PREFIX)
PREFIX_include = $(INCLUDE_PREFIX)

### The file name where release information is kept
RELEASE_FILE = $(PREFIX)/release

### The file name of the release tar file
RELEASE_TAR = $(OUT)-$(VERSION).tar.gz

### Stamp file name extenstion for various "profile" compilations
PURESTAMP            = $(PURESTAMP_$(OUT))$(PURESTAMP_on)
QUANTSTAMP           = $(QUANTSTAMP_$(OUT))$(QUANTSTAMP_on)
PROFILESTAMP         = $(PROFILESTAMP_$(OUT))$(PROFILESTAMP_on)
STAMPEXT             = $(PURESTAMP)$(QUANTSTAMP)$(PROFILESTAMP)

### Build directory stamp file
BUILDSTAMP = $(BUILD)/BOOTSTAMP$(BOOT:%=-%)

### Extra compilation options
STATICopt            = $(STATIC_on) $(STATIC_$(OUT))
PROFILEopt           = $(PROFILE_on) $(PROFILE_$(OUT))
PURIFYopt            = $(PURIFY_on) $(PURIFY_$(OUT))
QUANTIFYopt          = $(QUANTIFY_on) $(QUANTIFY_$(OUT))
#QUANTIFY = quantify -best-effort -collector=/cadappl/gcc/3.2.2/lib/gcc-lib/hppa2.0w-hp-hpux11.00/3.2.2/collect2

### All C preprocessing flags
_CPPFLAGS = $(CPPFLAGS) $(DEFS) -I$(SRCDIR) -I$(BUILD) $(INCLUDES)

### All C compilation flags
_CFLAGS = $(PROFILEopt) $(CFLAGS) $(_CPPFLAGS) $(TIM_AST_FLAGS)

### All C++ compilation flags
_CXXFLAGS = $(PROFILEopt) $(CXXFLAGS) $(_CPPFLAGS)

### All link flags
_LDFLAGS = $(LDFLAGS)

### All link libraries
_LIBS = $(LIBS) $(EXTRALIBS)

### Default target
###
### ----------------------------------------------------------------------------
default:: check-config all

### Progress message
###
### ----------------------------------------------------------------------------
..non-existant-include..:
	@ $(ENTERING) "$(patsubst $(ROOT)/%,%, $(patsubst %.mk, %, $(patsubst %/project.mk,%,$(SRC)/$(PROJECT))))"

### Help message, part 1
###
### ----------------------------------------------------------------------------
help:: 
	@ $(ECHO) "$(MAKE) [Targets] [Assignments]"
	@ $(ECHO) ""
	@ $(ECHO) "  all                       make everything"
	@ $(ECHO) "  install                   install binaries, libraries, and/or include files"
	@ $(ECHO) "  clean                     remove all generated files"
	@ $(ECHO) "  distclean                 remove all files and directories that do not belong in the source"
	@ $(ECHO) "                            directory, this will ask for confirmation"
	@ $(ECHO) "  help                      display this help message"
	@ $(ECHO) "  check-config              check whether the system configuration is valid"
	@ $(ECHO) "  list-requirements         list the requirements of the project"
	@ $(ECHO) "  <subdir>                  make and install everything in the subdirectory"
	@ $(ECHO) "                            subdir is one of: $(RELDIRS)"
	@ $(ECHO) 

### What to build and how.
### 
### ----------------------------------------------------------------------------
include $(SRC)/$(PROJECT)

### Derivations of FILES, like source files, etc
###
### ----------------------------------------------------------------------------
_FILES = $(FILES:%=$(SRCDIR)/%)
HEADERS = $(filter %.h, $(_FILES:$(SRCDIR)/%=%))
DOGS   = $(filter %.df, $(_FILES))
FRONTS = $(filter %.front, $(_FILES))
EGGS   = $(filter %.egg, $(FILES))
LEXS   = $(filter %.l, $(FILES))
YACCS  = $(filter %.y, $(FILES))
BNF    = $(filter %.bnf, $(_FILES))
MOCS   = $(filter %.m.h, $(_FILES))
UICS   = $(filter %.ui, $(_FILES))
GCSRCS += $(FRONTS:$(SRCDIR)/%.front=%.c)      		\
	  $(FRONTS:$(SRCDIR)/%.front=%_y.c)    		\
	  $(FRONTS:$(SRCDIR)/%.front=%_l.c) 		\
	  $(MOCS:$(SRCDIR)/%.m.h=moc_%.cc)              \
	  $(UICS:$(SRCDIR)/%.ui=%.cc)                   \
	  $(UICS:$(SRCDIR)/%.ui=moc_%.cc)               \
	  $(LEXS:%.l=%_l.c)                             \
	  $(YACCS:%.y=%_y.c)                            \
          $(EGGS:%.egg=%.c)

ifeq (,$(findstring -no-lalr, $(FRONTFLAGS)))
GCSRCS +=  $(FRONTS:$(SRCDIR)/%.front=%_lalr.c)
endif
ifneq (,$(findstring -multi-start, $(FRONTFLAGS)))
GCSRCS +=  $(FRONTS:$(SRCDIR)/%.front=%_parse.c)
endif
ifneq (,$(findstring -multi_start, $(FRONTFLAGS)))
GCSRCS +=  $(FRONTS:$(SRCDIR)/%.front=%_parse.c)
endif
ifneq (,$(findstring -gendump, $(FRONTFLAGS)))
GCSRCS +=  $(FRONTS:$(SRCDIR)/%.front=%_dump.c)
endif
ifneq (,$(findstring -bdump, $(FRONTFLAGS)))
GCSRCS +=  $(FRONTS:$(SRCDIR)/%.front=%_bdump.c)
endif
ifneq (,$(findstring -genprint, $(FRONTFLAGS)))
GCSRCS +=  $(FRONTS:$(SRCDIR)/%.front=%Print.c)
else
ifneq (,$(findstring -genpretty, $(FRONTFLAGS)))
GCSRCS +=  $(FRONTS:$(SRCDIR)/%.front=%Print.c)
endif
endif
CSRCS  = $(filter %.c, $(GCSRCS) $(_FILES))

CXXSRCS = $(filter %.cc, $(GCSRCS) $(_FILES)) \
          $(filter %.C, $(GCSRCS) $(_FILES)) \
          $(filter %.cpp, $(GCSRCS) $(_FILES))
OBJS  += $(CSRCS:%.c=%.o) $(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(CXXSRCS:%.C=%.o)))
OBJS  := $(patsubst $(SRCDIR)/%,%,$(OBJS))
DEPS   = $(patsubst $(SRCDIR)/%,%,$(CSRCS:%.c=%.d) \
           $(patsubst %.cc,%.d,$(patsubst %.cpp,%.d,$(CXXSRCS:%.C=%.d))) \
           $(DOGS:%=%.d) \
           $(FRONTS:%=%.d))

SUBDIRS = $(sort $(dir $(_FILES:$(SRCDIR)/%=%) $(PROJECTS) $(EXTERNALS)))
RELDIRS = $(sort $(patsubst %/,%,$(dir $(PROJECTS) $(EXTERNALS))))

# assumption : a LIBRARY_PATH is separated by either ';' or ':'
#              in the case of ';' paths can contain ':'
ifeq (;,$(findstring ;,$(LIBRARY_PATH)))
_USER_LIB_DIRS = $(patsubst ;, ,$(LIBRARY_PATH))
else
_USER_LIB_DIRS = $(patsubst :, ,$(LIBRARY_PATH))
endif
ifeq "$(UNAME)" "MINGW32"
# should work for all gcc's
_DEFAULT_LIB_DIRS = $(dir $(shell gcc -print-file-name=libm.a))
endif

LIBDIRS = $(patsubst -L%,%,$(filter -L%, $(_LDFLAGS)))
LIBDIRS += $(_USER_LIB_DIRS) $(_DEFAULT_LIB_DIRS)

DOCS = $(BNF:$(SRCDIR)/%.bnf=%.ps)


### Tools used for building
###
### ----------------------------------------------------------------------------
CPP   = cpp
CAT   = cat
GCC   = gcc
GXX   = g++
CC    = gcc
CXX   = g++
ifeq "0" "$(words $(CXXSRCS))"
LD    = $(QUANTIFYopt) $(PURIFYopt) $(CC) $(PROFILEopt) $(STATICopt)
LD_BARE = $(CC)
else
LD    = $(QUANTIFYopt) $(PURIFYopt) $(CXX) $(PROFILEopt) $(STATICopt)
LD_BARE = $(CXX)
endif
# for GNU   : LD_SHARED = $(LD) -Wl,-shared
# for HP-UX : LD_SHARED = $(LD) -Wl,-b
# for SunOS : LD_SHARED = $(LD) -Wl,-G
LD_SHARED = $(LD_BARE) -Wl,-shared
LD_RELOC = $(LD_BARE) -Wl,-r
BISON = bison
FLEX  = flex
FRONT = Front
EGG   = egg
DOGGY = doggy
DOT   = dot
MKDIR = mkdir -p
TOUCH = touch
CP    = cp
CP-R  = cp -r
LN    = ln
RM-RF = rm -rf
RM    = rm
ECHO  = echo
MSG   = $(ECHO)
ifneq "$(UNAME)" "MINGW32"
ENTERING = printf "%s ...  \r"
else
ENTERING = true
endif
WARNING = echo "Warning:"
ERROR   = echo "Error:"
AR    = ar rc
MV    = mv
TAR   = tar
STRIP = strip
SED   = sed
AWK   = awk
GREP  = grep
MOC   = $(QTDIR)/bin/moc
UIC   = $(QTDIR)/bin/uic
MESSAGE = $(MESSAGING); test 0 -ne $$? || $(MSG) "$(patsubst $(ROOT)/%,%, $(patsubst %.mk, %, $(patsubst %/project.mk,%,$(SRC)/$(PROJECT))))" "-"


-include $(CONFIG_FILES) ..non-existant-include..

### Link options
###
### ----------------------------------------------------------------------------
PROFILE_$(PROFILE)      = -pg
PROFILESTAMP_$(PROFILE) = PROF.
QUANTIFYFLAGS           = -best-effort
QUANTIFY_$(QUANTIFY)    = quantify $(QUANTIFYFLAGS)
QUANTSTAMP_$(QUANTIFY)  = QUANT.
PURIFYFLAGS             = -best-effort -collector=/cadappl/gcc/3.2.1/lib/gcc-lib/hppa2.0w-hp-hpux11.00/3.2.1/collect2
PURIFY_$(PURIFY)        = purify $(PURIFYFLAGS)
PURESTAMP_$(PURIFY)     = PURE.
STATIC_$(STATIC)        = -static

### Personal preferences
###  VERBOSE   - Echo command when compiling
###  MESSAGING - Echo what is happening, (eg.: "Compiling foo.c")
###
### ----------------------------------------------------------------------------
MESSAGING = true
VERBOSE   = false
-include $(HOME)/.projectrc

### Command line options
###
### ----------------------------------------------------------------------------
ifeq "$(filter-out +%, $(MAKECMDGOALS))" ""
CLI_DEP=default
endif

+v : $(CLI_DEP)
#
ifneq "$(findstring +v, $(MAKECMDGOALS))" ""
MAKE := $(MAKE) "VERBOSE=true"
override VERBOSE=true
endif

+no-reqs : $(CLI_DEP)
#
DO_REQS=$(REQUIRES:%=require/%)
ifneq "$(findstring +no-reqs, $(MAKECMDGOALS))" ""
MAKE := $(MAKE) "DO_REQS="
override DO_REQS=
endif

+no-deps : +no-reqs $(CLI_DEP)
#
DO_DEPS=deps
ifneq "$(findstring +no-deps, $(MAKECMDGOALS))" ""
MAKE := $(MAKE) "DO_REQS="
override DO_REQS=
MAKE := $(MAKE) "DO_DEPS="
override DO_REQS=
endif

### Help message, part 2
###
### ----------------------------------------------------------------------------
help:: 
	@ $(ECHO)
	@ $(ECHO) '  +v                        Echo commands as they are executed.'
	@ $(ECHO) '  +no-reqs                  Do not follow requirements; on MINGW this is automatically set.'
	@ $(ECHO) '  +no-deps                  Do not compute dependencies and do not follow requirements.'
	@ $(ECHO)
	@ $(ECHO) '  VERBOSE={true,false}      Echo commands as they are executed. [currently $(VERBOSE)]'
	@ $(ECHO) "  MESSAGING={true,false}    Echo what's happening, eg: \"Compiling foo.c\" [currently $(MESSAGING)]"
	@ $(ECHO) '  QUANTIFY={on,off,$$(OUT)}  Turn on quantify for all projects or for a specify project, default off'
	@ $(ECHO) '  QUANTIFYFLAGS             Quantify options. [currently $(QUANTIFYFLAGS)]'
	@ $(ECHO) '  PURIFY={on,off,$$(OUT)}    Turn on purify for all projects or for a specify project, default off'
	@ $(ECHO) '  PURIFYFLAGS               Purify options. [currently $(PURIFYFLAGS)]'
	@ $(ECHO) '  PROFILE={on,off,$$(OUT)}   Turn on profiling for all projects or for a specify project, default off'
	@ $(ECHO) '  STATIC={on,off,$$(OUT)}    Link binaries statically for all projects or for a specify project, default off'
	@ $(ECHO) 
	@ $(ECHO) '(assignments are also read from ~/.projectrc)'

### GNU make settings
###
### ----------------------------------------------------------------------------
.PHONY: $(RELDIRS) all clean deps install shadow-install default
.PHONY: Makefile ..non-existant-include..
.SUFFIXES:
.SECONDARY:
.DELETE_ON_ERROR: $(DEPS)

ifneq "$(VERBOSE)" "true"
.SILENT:
endif

### Targets
###
### ---------------------------------------------------------------------------
all: once-all
all-once: $(DEFAULT)

clean: $(PROJECTS:%=project/%/clean) $(EXTERNALS:%=external/%/clean)
	$(RM-RF) $(BUILD)

deps: build/deps

#ifneq "$(UNAME)" "MINGW32"
#list-requirements: $(REQUIRES:%=require/%/list) $(PROJECTS:%=project/%/listreq)
#else
list-requirements: 
#endif

### check configuration
###
### ----------------------------------------------------------------------------
-include $(_CURDIR)/have-curdir
$(_CURDIR)/have-curdir:
/have-curdir:
	@ $(ECHO)
	@ $(ECHO) "*** WARNING: old GNU make, not version 3.79.1, using ROOT=$(ROOT)"
	@ $(ECHO)
check-config:: 
	if [ -z "$(FRONTS)" ] || $(MAKE) -n "VPATH=$(PATH)" $(FRONT); then true; else \
		$(WARNING) "$(FRONT) not executable"; \
	fi
	if [ -z "$(DOGS)" ] || $(MAKE) -n "VPATH=$(PATH)" $(DOGGY); then true; else \
		$(WARNING) "$(DOGGY) not executable"; \
	fi

### Sub projects, and requirements
###
### ----------------------------------------------------------------------------
$(RELDIRS):
	$(MAKE) -f $(ROOT)/Makefile project/$@/project.mk

EXISTS = if [ ! -r $(*D) ]; then $(ERROR) "Directory \`$(*D)' does not exist"; false; fi

require/%: %
	@ $(EXISTS)
	cd $(*D); $(MAKE) -f $(ROOT)/Makefile all shallow-install "PROJECT=$(*F)" "ROOT=$(ROOT)"

require/%:
	@ $(WARNING) "Required project $* does not exist"

require/%/list: %
	@ $(MESSAGE) "Requires" $*
	@ $(EXISTS)

external/%: $(SRC)/%
	@ $(EXISTS)
	cd $<; $(MAKE) all install

external/%/clean: $(SRC)/%
	@ $(EXISTS)
	cd $<; $(MAKE) clean

external/%/install: $(SRC)/%
	@ $(EXISTS)
	cd $<; $(MAKE) install

project/%: $(SRC)/% $(DO_REQS)
	@ $(EXISTS)
	cd $(SRC)/$(*D); $(MAKE) -f $(ROOT)/Makefile all shallow-install "PROJECT=$(*F)" "ROOT=$(ROOT)"

project/%/clean: $(SRC)/%
	@ $(EXISTS)
	cd $(SRC)/$(*D); $(MAKE) -f $(ROOT)/Makefile clean "PROJECT=$(*F)" "ROOT=$(ROOT)"

project/%/install: $(SRC)/%
	@ $(EXISTS)
	cd $(SRC)/$(*D); $(MAKE) -f $(ROOT)/Makefile install "PROJECT=$(*F)" "ROOT=$(ROOT)"

project/%/listreq: $(SRC)/%
	@ $(EXISTS)
	cd $(SRC)/$(*D); $(MAKE) -f $(ROOT)/Makefile list-requirements "PROJECT=$(*F)" "ROOT=$(ROOT)"

project/%/print_noclean: $(SRC)/%
	@ $(EXISTS)
	cd $(SRC)/$(*D); $(MAKE) -f $(ROOT)/Makefile print_noclean "PROJECT=$(*F)" "ROOT=$(ROOT)"

project/%/do-distclean: $(SRC)/%
	@ $(EXISTS)
	$(MAKE) -f $(ROOT)/Makefile do-distclean "SRC=$(patsubst %/.,%,$(SRC)/$(*D))" "PROJECT=$(*F)" "ROOT=$(ROOT)" "NOCLEAN=$(NOCLEAN)"

### distclean
###
### ----------------------------------------------------------------------------
get_dist: $(BUILDSTAMP)
	$(MAKE) -C $(SRC) -f $(ROOT)/Makefile print_noclean \
		"ROOT=$(ROOT)" 2> $(BUILD)/ALL_FILES

print_noclean: $(PROJECTS:%=project/%/print_noclean)
	@ $(ECHO) "$(RELSRC)$(MAKEFILE)" 1>&2
	@ $(ECHO) "$(RELSRC)$(PROJECT)" 1>&2
	@ $(ECHO) "$(_FILES:%=$(RELSRC)%)" 1>&2
	@ $(ECHO) "$(NOCLEAN:%=$(RELSRC)%)" 1>&2

distclean: get_dist
	$(MAKE) -C $(SRC) -f $(ROOT)/Makefile do-distclean \
		"NOCLEAN=$(SUBDIRS) `cat $(BUILD)/ALL_FILES  | tr '\n' ' '`" \
		"ROOT=$(ROOT)"

do-distclean: distclean-message \
	      $(patsubst %,echo/%,$(wildcard $(RELSRC)*)) \
	      distclean-query \
	      $(patsubst %,clean/%,$(wildcard $(RELSRC)*)) $(PROJECTS:%=project/%/do-distclean)
$(sort $(NOCLEAN:%=clean/%)) $(sort $(NOCLEAN:%=echo/%)):
	@ 
clean/%:
	$(RM-RF) $*
echo/%:
	@ $(ECHO) "  $*"
distclean-message:
	@ $(MESSAGE) "The following files will be removed"

distclean-query:
	@ $(ECHO)
	@ $(ECHO) "ok? [yn]"
	read yes && [ "$$yes" = "y" ]

### Release
###
### ----------------------------------------------------------------------------
release package dist: $(RELEASE_TAR)

release-query:
ifndef NOQUERY
	@ $(ECHO) "Release $(RELEASE_TAR)? [yn]"
	@ read yes && [ "$$yes" = "y" ]
endif

$(RELEASE_TAR): $(BUILD)/release release-query
	cd $(PREFIX); \
	  $(RM-RF) bin.old; \
	  $(CP-R) bin bin.old; \
	  $(STRIP) bin/[a-zA-Z]* || true
	cd $(BUILD); \
	  $(CAT) $< \
	| $(AWK) '{ print $$2 }' \
	| $(SED) -e 's^$(BUILD)/^^g' \
	| $(TAR) vzcfT $(SRC)/$@ -
	cd $(PREFIX); \
	  $(MV) bin.old/* bin; \
	  $(RM-RF) bin.old

### Install
###
### ----------------------------------------------------------------------------
install: once-install
install-once: shallow-install $(PROJECTS:%=project/%/install) $(EXTERNALS:%=external/%/install)
shallow-install: once-shallow-install
shallow-install-once: $(BUILD)/$(BUILD_MAKEFILE) build/shallow-install
do-shallow-install: $(INSTALL_MAKEFILE) cleanup-release
	$(MAKE) -C $(BUILD) -f $(INSTALL_MAKEFILE) generated-install
	@ if [ -r $(BUILD)/release -a $(PREFIX) != $(BUILD) ]; then \
	  $(MV) $(BUILD)/release $(RELEASE_FILE); \
	fi

cleanup-release:
	@ if [ -r $(RELEASE_FILE) ]; then \
	  grep -v "^$(SRC)/$(PROJECT) " $(RELEASE_FILE) > $(BUILD)/release; \
	fi || true

INSTALL_SELECT = $(patsubst $*/%, %, $(filter $*/%, $(INSTALL) $(RELEASE))) $(INSTALL_$*) $(RELEASE_$*)
RELEASE_SELECT = $(patsubst $*/%, %, $(filter $*/%, $(RELEASE))) $(RELEASE_$*)
PREFIX_SELECT  = $(firstword $(PREFIX_$*) $(PREFIX)/$*)

$(INSTALL_MAKEFILE): $(SRC)/$(PROJECT)
	@ $(MESSAGE) "Generating install makefile"
	$(CP) $(ROOT)/$(MAKEFILE) $@
	$(MAKE) -C $(BUILD) -f $(BUILD_MAKEFILE) $(INSTALL_CATEGORIES:%=gen-make-install-%)

gen-make-install-%:
	$(MAKE) -C $(BUILD) -f $(BUILD_MAKEFILE) gen-make-install-category \
		"CAT_PREFIX=$(PREFIX_SELECT)" "CAT_INSTALL=$(INSTALL_SELECT)" \
		"CAT_RELEASE=$(RELEASE_SELECT)"
gen-make-install-category: $(CAT_INSTALL:%=gen-install/%) $(CAT_RELEASE:%=gen-release/%)
	$(ECHO) 'generated-install:: $(patsubst %, $(CAT_PREFIX)/%, $(notdir $(CAT_INSTALL)))' >> $(INSTALL_MAKEFILE)
	$(ECHO) "	true"                                                                >> $(INSTALL_MAKEFILE)
gen-install/%: $(SRCDIR)/%
	$(ECHO) "$(CAT_PREFIX)/$(*F) :: $(SRCDIR)/$*"                                        >> $(INSTALL_MAKEFILE)
	$(ECHO) '	@ $$(MESSAGE) "Installing $$(@F) in $(CAT_PREFIX)"'                  >> $(INSTALL_MAKEFILE)
	$(ECHO) '	if [ ! -d $(CAT_PREFIX) ]; then mkdir -p $(CAT_PREFIX); fi'          >> $(INSTALL_MAKEFILE)
	$(ECHO) '	cmp -s $$< $$@ || cp -r $$< $$@'                                     >> $(INSTALL_MAKEFILE)
gen-install/%: $(BUILD)/%
	$(ECHO) "$(CAT_PREFIX)/$(*F) :: $(BUILD)/$*"                                         >> $(INSTALL_MAKEFILE)
	$(ECHO) '	@ $$(MESSAGE) "Installing $$(@F) in $(CAT_PREFIX)"'                  >> $(INSTALL_MAKEFILE)
	$(ECHO) '	if [ ! -d $(CAT_PREFIX) ]; then mkdir -p $(CAT_PREFIX); fi'          >> $(INSTALL_MAKEFILE)
	$(ECHO) '	cmp -s $$< $$@ || cp -r $$< $$@'                                     >> $(INSTALL_MAKEFILE)
gen-install/%:
	$(ECHO) "$(CAT_PREFIX)/$(*F) :: $*"                                                  >> $(INSTALL_MAKEFILE)
	$(ECHO) '	@ $$(MESSAGE) "Installing $$(@F) in $(CAT_PREFIX)"'                  >> $(INSTALL_MAKEFILE)
	$(ECHO) '	if [ ! -d $(CAT_PREFIX) ]; then mkdir -p $(CAT_PREFIX); fi'          >> $(INSTALL_MAKEFILE)
	$(ECHO) '	cmp -s $$< $$@ || cp -r $$< $$@'                                     >> $(INSTALL_MAKEFILE)

gen-release/%:
	$(ECHO) "$(CAT_PREFIX)/$(*F) ::"                                                     >> $(INSTALL_MAKEFILE)
	$(ECHO) '	$(ECHO) $(SRC)/$(PROJECT) $$@ >> $(BUILD)/release'                   >> $(INSTALL_MAKEFILE)


### Result
###
### ----------------------------------------------------------------------------
do-all: $(RESULT) $(DOCS) $(EXTRA) $(BOOT:%=do-boot)

vpath %.a $(LIBDIRS)
vpath -l% $(LIBDIRS)
binary: $(STAMPEXT)BINARY.$(OUT).STAMP
$(STAMPEXT)BINARY.$(OUT).STAMP: $(OBJS) $(LIBS) $(ROOT)/$(MAKEFILE)
	@ $(MESSAGE) "Linking" $(OUT)
	if [ -f $(OUT) ]; then $(RM) $(OUT); fi
	$(LD) $(_LDFLAGS) -o $(OUT) $(OBJS) $(_LIBS)
	$(RM) *BINARY.$(OUT).STAMP 2>&1 | true 
	@ $(TOUCH) $@

library: LIBRARY.$(OUT).STAMP
LIBRARY.$(OUT).STAMP: $(LIBADD) $(shell ls "$(LIBOPTADD)" 2>/dev/null) $(OBJS) $(ROOT)/$(MAKEFILE)
	@ $(MESSAGE) "Creating" $(OUT)
	if [ -f $(OUT) ]; then $(RM) $(OUT); fi
	if [ -f "$(LIBOPTADD)" ]; then $(CP) $(LIBOPTADD) $(OUT); fi
#       if LIBADD is defined, it overrides LIBOPTADD
	if [ -n "$(LIBADD)" ]; then $(CP) $(LIBADD) $(OUT); fi
	$(AR) $(OUT) $(OBJS)
	@ $(TOUCH) $@

objectfile: PARTIAL.$(OUT).STAMP
PARTIAL.$(OUT).STAMP: $(OBJS) $(LIBS) $(ROOT)/$(MAKEFILE)
	@ $(MESSAGE) "Creating" $(OUT)
	if [ -f $(OUT) ]; then $(RM) $(OUT); fi
	$(LD_RELOC) $(_LDFLAGS) -o $(OUT) $(OBJS) $(_LIBS)
	@ $(TOUCH) $@

sharedlib.a: SHAREDLIB.a.$(OUT).STAMP
SHAREDLIB.a.$(OUT).STAMP: $(OBJS) $(ROOT)/$(MAKEFILE)
	@ $(MESSAGE) "Creating" $(OUT:.so=.a)
	if [ -f $(OUT:.so=.a) ]; then $(RM) $(OUT:.so=.a); fi
	$(AR) $(OUT:.so=.a) $(OBJS)
	@ $(TOUCH) $@

sharedlib: sharedlib.a SHAREDLIB.$(OUT).STAMP
SHAREDLIB.$(OUT).STAMP: $(OBJS) $(ROOT)/$(MAKEFILE)
	@ $(MESSAGE) "Creating" $(OUT)
	if [ -f $(OUT) ]; then $(RM) $(OUT); fi
	$(LD_SHARED) $(_LDFLAGS) -o $(OUT) $(OBJS)
	@ $(TOUCH) $@

### Boot directory
###
### ----------------------------------------------------------------------------
do-boot: $(patsubst $(BUILD)/%, $(SRC)/$(BOOT)/%, $(wildcard $(BUILD)/*.[chyl]))
$(SRC)/$(BOOT)/%: $(BUILD)/%
	@ if [ ! -d $(SRC)/$(BOOT) ]; then $(MKDIR) $(SRC)/$(BOOT); fi
	@ $(MESSAGE) "Creating boot version" $*
	$(CP) -p $< $@

### Build directory
###
### ----------------------------------------------------------------------------
$(BUILD)/STAMP :
	if [ ! -r $(BUILD) ]; then $(MKDIR) $(BUILD); fi
	$(TOUCH) $(BUILD)/STAMP

$(BUILD)/BOOTSTAMP$(BOOT:%=-%) : $(BUILD)/STAMP
	-if [ -n "$(BOOT)" ] && [ -d $(SRC)/$(BOOT) ]; then \
		$(MESSAGE) "Booting"; \
		$(CP)  $(BOOT)/* $(BUILD); \
	fi
	$(TOUCH) $@

build/deps: $(BUILD)/$(BUILD_MAKEFILE) 
build/all: $(DO_REQS) $(PROJECTS:%=project/%) $(EXTERNALS:%=external/%) $(DO_DEPS)
build/shallow-install: all
build/% : 
	$(MAKE) -C $(BUILD) -f $(BUILD_MAKEFILE) do-$* "SRC=$(_CURDIR)" "ROOT=$(ROOT)"

### Dependency generation
###
### ----------------------------------------------------------------------------
$(BUILD)/$(BUILD_MAKEFILE): $(BUILDSTAMP) $(ROOT)/$(MAKEFILE)
	$(CP) $(ROOT)/$(MAKEFILE) $(BUILD)/$(BUILD_MAKEFILE)

do-deps: MAKE.STAMP

MAKE.STAMP: $(ROOT)/$(MAKEFILE) $(DEPS)
	$(MESSAGE) 'Creating' '$$(BUILD)/$(BUILD_MAKEFILE)'
	$(CAT) $(ROOT)/$(MAKEFILE) $(DEPS) > $(BUILD_MAKEFILE)
	$(TOUCH) $@
$(GCSRCS) $(DEPS) $(OBJS): $(ROOT)/$(MAKEFILE) $(SRC)/$(PROJECT)

### Once
###
### ----------------------------------------------------------------------------
once-%:
	if [ ! -r $(BUILD)/$(PROJECT).$*.tag ] || [ `cat $(BUILD)/$(PROJECT).$*.tag` != $(TAG) ]; then \
		$(MAKE) -C $(SRC) -f $(ROOT)/$(MAKEFILE) $*-once && \
		echo $(TAG) > $(BUILD)/$(PROJECT).$*.tag; \
	fi

### Internal targets
###
### ----------------------------------------------------------------------------
_print-%:
	@ $(ECHO) $($*:%=$(SRCDIR)/%) 1>&2

show-%:
	@ $(ECHO) $($*)

### Implicit rules
###
### ----------------------------------------------------------------------------

### Objects
%.o : $(SRCDIR)/%.c
	@ $(MESSAGE) "Compiling" "$*.c" 
	$(CC) -c $< $(_CFLAGS) -o $@
%.o : %.c
	@ $(MESSAGE) "Compiling" "$*.c" 
	$(CC) -c $< $(_CFLAGS) -o $@
%.o : $(SRCDIR)/%.cc
	@ $(MESSAGE) "Compiling" "$*.cc" 
	$(CXX) -c $< $(_CXXFLAGS) -o $@
moc_%.cc : $(SRCDIR)/%.m.h
	@ $(MESSAGE) "MOCing" "$*.m.h" 
	$(MOC) $< -o $@
moc_%.cc : %.m.h
	@ $(MESSAGE) "MOCing" "$*.m.h"
	$(MOC) $< -o $@
%.m.h : $(SRCDIR)/%.ui
	@ $(MESSAGE) "UICing" "$*.ui"
	$(UIC) $< -o $@
%.cc : $(SRCDIR)/%.ui %.m.h
	@ $(MESSAGE) "UICing" "$*.ui"
	$(UIC) $< -i $*.m.h -o $@
%.o : %.cc
	@ $(MESSAGE) "Compiling" "$*.cc" 
	$(CXX) -c $< $(_CXXFLAGS) -o $@
%.o : $(SRCDIR)/%.C
	@ $(MESSAGE) "Compiling" "$*.C" 
	$(CXX) -c $< $(_CXXFLAGS) -o $@
%.o : %.C
	@ $(MESSAGE) "Compiling" "$*.C" 
	$(CXX) -c $< $(_CXXFLAGS) -o $@
%.o : $(SRCDIR)/%.cpp
	@ $(MESSAGE) "Compiling" "$*.cpp" 
	$(CXX) -c $< $(_CXXFLAGS) -o $@
%.o : %.cpp
	@ $(MESSAGE) "Compiling" "$*.cpp" 
	$(CXX) -c $< $(_CXXFLAGS) -o $@
### Dependencies
%.df.d : $(SRCDIR)/%.df
	@ $(ECHO) "$@ \\" > $@
	$(CAT) $< | $(CPP) -w -MM -MG $(DOGPPFLAGS) -  | $(SED) -e 's/^-/$$(BUILD)\/$*_doggy.c $*_doggy.c/' >> $@
%.front.d : $(SRCDIR)/%.front
	@ $(ECHO) "$@ \\" > $@
	$(CAT) $< | $(CPP) -w -MM -MG -I$(SRC) -I$(SRCDIR) -  | $(SED) -e 's/^-/$$(BUILD)\/$*.c $*.c/' >> $@
%.d : $(SRCDIR)/%.c
	@ $(ECHO) "$@ \\" > $@
	$(GCC) -w -MM -MG $< $(_CPPFLAGS) >> $@
%.d : %.c
	@ $(ECHO) "$@ \\" > $@
	$(GCC) -w -MM -MG $< $(_CPPFLAGS) >> $@
%.d : $(SRCDIR)/%.cc
	@ $(ECHO) "$@ \\" > $@
	@ $(GXX) -w -MM -MG $< $(_CPPFLAGS) >> $@
%.d : %.cc
	@ $(ECHO) "$@ \\" > $@
	@ $(GXX) -w -MM -MG $< $(_CPPFLAGS) >> $@
%.d : $(SRCDIR)/%.C
	@ $(ECHO) "$@ \\" > $@
	@ $(GXX) -w -MM -MG $< $(_CPPFLAGS) >> $@
%.d : %.C
	@ $(ECHO) "$@ \\" > $@
	@ $(GXX) -w -MM -MG $< $(_CPPFLAGS) >> $@
%.d : $(SRCDIR)/%.cpp
	@ $(ECHO) "$@ \\" > $@
	@ $(GXX) -w -MM -MG $< $(_CPPFLAGS) >> $@
%.d : %.cpp
	@ $(ECHO) "$@ \\" > $@
	@ $(GXX) -w -MM -MG $< $(_CPPFLAGS) >> $@
### Bison & Flex 
%_y.c %_y.h: $(SRCDIR)/%.y
	@ $(MESSAGE) "Generating" "$*_y.c" 
	$(BISON) -v -d -l -p $*_ -o $*_y.c $<
%_l.c: $(SRCDIR)/%.l %_y.h
	@ $(MESSAGE) "Generating" "$*_l.c" 
	$(FLEX) -s -L -P$*_ -o$@ $<
%_y.c %_y.h: %.y
	@ $(MESSAGE) "Generating" "$*_y.c" 
	$(BISON) -v -d -l -p $*_ -o $*_y.c $<
%_l.c: %.l %_y.h
	@ $(MESSAGE) "Generating" "$*_l.c" 
	$(FLEX) -s -L -P$*_ -o$@ $<
### egg
%.c %.h: $(SRC)/%.egg $(EGG)
	@ $(MESSAGE) "Generating" "$*.c"
	$(CPP) $(_CPPFLAGS) $< | $(EGG) $(EGGFLAGS) - -o $*
### Front
%Print.c %Print.h \
%_parse.c %_parse.h \
%.types %.md \
%.c %.l %.y %.h %_lalr.c %_lalr.h: $(SRCDIR)/%.front $(FRONT)
	@ $(MESSAGE) "Generating" "$* parser" 
	$(FRONT) $(FRONTFLAGS) $<
%.ps: $(SRCDIR)/%.bnf
	@ $(MESSAGE) "Generating" "$* diagrams" 
	$(FRONT) $(FRONTFLAGS) -nocode -diagrams $(DIAGRAMSFLAGS) $<

### Doggy    (somehow this needs the "$(BUILD)/%_doggy.c" target, don't know why)
%_doggy.c $(BUILD)/%_doggy.c: $(SRCDIR)/%.df $(DOGGY)
	@ $(MESSAGE) "Generating" "$*_doggy.c" 
	$(CAT) $< | $(CPP) $(DOGPPFLAGS) - | $(DOGGY) $(DOGFLAGS) -f $* -o $@
### default  
%.h:
	@ $(WARNING) "Could not find $@, trying to continue"

###
### Dependencies will be added below.
### ----------------------------------------------------------------------------
egg.d \
egg.o: egg.c \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/old_error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/hash.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/front_list.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/mem.h \
 egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/print_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 egg_parse.h egg_defs.h
egg_y.d \
egg_y.o: egg_y.c \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/hash.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/front_list.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/old_error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/parse_support.h \
 egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/print_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 egg_parse.h egg_defs.h
egg_l.d \
egg_l.o: egg_l.c egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/hash.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/front_list.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/old_error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/print_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 egg_parse.h egg_defs.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/parse_support.h \
 egg_y.h
egg_lalr.d \
egg_lalr.o: egg_lalr.c egg_lalr.h egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/hash.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/front_list.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/old_error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/print_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 egg_parse.h egg_defs.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/parse_support.h \
 egg_y.h
egg_parse.d \
egg_parse.o: egg_parse.c \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/parse_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/hash.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/front_list.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/old_error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/mem.h \
 egg_parse.h egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/print_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 egg_defs.h egg_lalr.h
eggPrint.d \
eggPrint.o: eggPrint.c eggPrint.h egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/hash.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/front_list.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/old_error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/print_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 egg_parse.h egg_defs.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/text.h
main.d \
main.o: \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/main.c \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/old_error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/flags.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/filename.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/init.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/hash.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/front_list.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/print_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg_parse.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg_defs.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/messenger.h
init.d \
init.o: \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/init.c \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/hash.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/front_list.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/old_error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/print_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg_parse.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg_defs.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/init.h
messenger.d \
messenger.o: \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/messenger.c \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/text.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/mem.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/old_error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/filename.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/hash.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/front_list.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/basic_types.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/error.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/scan_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/print_support.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/../Linux/include/front/SymTab.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg_parse.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/egg_defs.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/Linux/eggPrint.h \
 /home/gunter/GM_LANGUAGES/COMPILER/FRONT/front-20161220/egg/messenger.h
egg.front.d \
$(BUILD)/egg.c egg.c: 
