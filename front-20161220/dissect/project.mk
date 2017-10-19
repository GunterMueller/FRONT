# RESULT determines what will be built, set to library or binary
RESULT     = binary

REQUIRES   = $(FRONT_ROOT)/libfront/project.mk
PROJECTS   = library.mk

# The filename of the output
OUT        = dissect

CONFIG_FILES = $(FRONT_ROOT)/Config.mk
LIBADD     = 

# Where everything will be installed
PREFIX   = $(FRONT_ROOT)/$(UNAME)

# What will be installed, and where.
# can be. bin/aap, lib/libnoot.a include/mies.h
INSTALL    = bin/$(OUT)

# _All_ files in the project.
FILES      =  main.c \
              alloc.c alloc.h \
              binary.c binary.h \
              draw.c draw.h \
              graph.c graph.h \
              input.c input.h \
              readlog.c readlog.h \
              stack.c stack.h

DEFS     = -D_LARGEFILE64_SOURCE
INCLUDES = -I$(FRONT_ROOT)/$(UNAME)/include
CPPFLAGS = 
CFLAGS   = -g -W -Wall -m32
#-finstrument-functions

LIBS     = -lfront -lm
#-ldissect
LDFLAGS  = -L$(PREFIX)/lib -L$(BUILD) /usr/lib/libelf.so.1 -m32

BUILD    = $(SRC)/$(UNAME)

