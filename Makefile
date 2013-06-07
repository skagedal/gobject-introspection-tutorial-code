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

CFLAGS=`pkg-config --cflags glib-2.0 gobject-2.0` -g 
LIBS=`pkg-config --libs glib-2.0 gobject-2.0` 

OBJECTS=tut-greeter.o main.o
SOURCES=tut-greeter.c tut-greeter.h main.c

all: greeter

greeter: $(OBJECTS)	
	$(CC) -o $@ $(OBJECTS) $(LIBS)

tut-greeter.o: tut-greeter.c tut-greeter.h
main.o: main.c tut-greeter.h

clean:
	rm *.o greeter
