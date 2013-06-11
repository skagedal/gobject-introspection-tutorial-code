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
#include <girepository.h>
#include "tut-greeter.h"

int main (int argc, char *argv[]) 
{
    TutGreeter *greeter;
    GOptionContext *ctx;
    GError *error = NULL;

    ctx = g_option_context_new (NULL);
    g_option_context_add_group (ctx, g_irepository_get_option_group ());

    if (!g_option_context_parse (ctx, &argc, &argv, &error)) {
	g_print ("greeter: %s\n", error->message);
	return 1;
    }

    greeter = tut_greeter_new ();
    tut_greeter_greet (greeter);

    return 0;
}
