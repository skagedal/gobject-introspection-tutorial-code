#
# GOBject Introspection Tutorial 
# 
# Written in 2013 by Simon Kågedal Reimer <skagedal@gmail.com>
#
# To the extent possible under law, the author have dedicated all
# copyright and related and neighboring rights to this software to
# the public domain worldwide. This software is distributed without
# any warranty.
#
# CC0 Public Domain Dedication:
# http://creativecommons.org/publicdomain/zero/1.0/

CC=gcc
C_INCLUDES=`pkg-config --cflags gobject-2.0`
CFLAGS=$(C_INCLUDES) -g
LIBS=`pkg-config --libs gobject-2.0`
LIBDIR=/usr/local/lib

OBJECTS=tut-greeter.lo
SOURCES=tut-greeter.c tut-greeter.h 

NAMESPACE=Tut
NSVERSION=0.1
GIR_FILE=$(NAMESPACE)-$(NSVERSION).gir
TYPELIB_FILE=$(NAMESPACE)-$(NSVERSION).typelib

all: libtutorial.la $(TYPELIB_FILE)

libtutorial.la: $(OBJECTS)	
	libtool link $(CC) $(LIBS) -rpath $(LIBDIR) $(OBJECTS) -o $@ 

$(TYPELIB_FILE): $(GIR_FILE)
	g-ir-compiler $(GIR_FILE) --output=$(TYPELIB_FILE)

$(GIR_FILE): tut-greeter.c tut-greeter.h
	libtool exec g-ir-scanner $^ --library=tutorial $(C_INCLUDES) --include=GObject-2.0 --namespace=$(NAMESPACE) --nsversion=$(NSVERSION) --output=$@

tut-greeter.lo: tut-greeter.c tut-greeter.h
	libtool compile $(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm *.lo libtutorial.la $(TYPELIB_FILE) $(GIR_FILE)
	-rm -rf .libs


