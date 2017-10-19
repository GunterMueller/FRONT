# RESULT determines what will be built, set to library or binary
RESULT     = library

REQUIRES   = $(FRONT_ROOT)/libfront/project.mk
PROJECTS   = 

# The filename of the output
OUT        = libdissect.a

CONFIG_FILES = $(FRONT_ROOT)/Config.mk
LIBADD     = 

# Where everything will be installed
PREFIX   = $(FRONT_ROOT)/$(UNAME)

# What will be installed, and where.
# can be. bin/aap, lib/libnoot.a include/mies.h
INSTALL    = lib/$(OUT)

# _All_ files in the project.
FILES      =  dissect.c

DEFS     = -D_LARGEFILE64_SOURCE
INCLUDES = -I$(FRONT_ROOT)/$(UNAME)/include
CPPFLAGS = 
CFLAGS   = -g -W -Wall -m32

BUILD    = $(SRC)/$(UNAME)

