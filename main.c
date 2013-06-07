/* -*- Mode: c; c-basic-offset: 4 -*- 
 *
 * GOBject Introspection Tutorial 
 * 
 * Written in 2013 by Simon Kågedal Reimer <skagedal@gmail.com>
 *
 * To the extent possible under law, the author have dedicated all
 * copyright and related and neighboring rights to this software to
 * the public domain worldwide. This software is distributed without
 * any warranty.
 *
 * CC0 Public Domain Dedication:
 * http://creativecommons.org/publicdomain/zero/1.0/
 */

#include <glib.h>
#include "tut-greeter.h"

int main (int argc, char *argv[]) 
{
    TutGreeter *greeter;

    greeter = tut_greeter_new ();
    tut_greeter_greet (greeter);

    return 0;
}
