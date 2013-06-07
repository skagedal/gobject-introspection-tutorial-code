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

#include <stdio.h>
#include "tut-greeter.h"

/**
 * SECTION: tut-greeter
 * @short_description: A greeter.
 *
 * The #TutGreeter is a class to display friendly greetings.
 */

G_DEFINE_TYPE (TutGreeter, tut_greeter, G_TYPE_OBJECT)

#define TUT_GREETER_GET_PRIVATE(o)	\
    (G_TYPE_INSTANCE_GET_PRIVATE ((o), TUT_GREETER_TYPE, TutGreeterPrivate))

struct _TutGreeterPrivate {
    gchar *greetee;		/* The entity to greet */
};

enum
{
    PROP_0,

    PROP_GREETEE,

    N_PROPERTIES
};

static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };

static void
tut_greeter_init (TutGreeter *object)
{
    TutGreeterPrivate *priv = TUT_GREETER_GET_PRIVATE (object);

    priv->greetee = NULL;
}

static void
tut_greeter_finalize (GObject *object)
{
    TutGreeterPrivate *priv = TUT_GREETER_GET_PRIVATE (object);

    g_free (priv->greetee);
    G_OBJECT_CLASS (tut_greeter_parent_class)->finalize (object);
}

static void
tut_greeter_set_property (GObject      *object,
			  guint         property_id,
			  const GValue *value,
			  GParamSpec   *pspec)
{
    TutGreeterPrivate *priv = TUT_GREETER_GET_PRIVATE (object);

    switch (property_id) {
    case PROP_GREETEE:
	g_free (priv->greetee);
	priv->greetee = g_value_dup_string (value);
	break;

    default:
	G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
	break;
    }
}

static void
tut_greeter_get_property (GObject    *object,
			  guint       property_id,
			  GValue     *value,
			  GParamSpec *pspec)
{
    TutGreeterPrivate *priv = TUT_GREETER_GET_PRIVATE (object);

    switch (property_id) {
    case PROP_GREETEE:
	g_value_set_string (value, priv->greetee);
	break;

    default:
	G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
	break;
    }
}

static void
tut_greeter_class_init (TutGreeterClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);

    object_class->set_property = tut_greeter_set_property;
    object_class->get_property = tut_greeter_get_property;
    object_class->finalize = tut_greeter_finalize;

    obj_properties[PROP_GREETEE] = 
	g_param_spec_string ("greetee",
			     "Greetee",
			     "The entity to greet.",
			     "World",
			     G_PARAM_READWRITE |
			     G_PARAM_CONSTRUCT);

    g_object_class_install_properties (object_class,
				       N_PROPERTIES,
				       obj_properties);

    g_type_class_add_private (object_class, sizeof (TutGreeterPrivate));
}


/**
 * tut_greeter_new:
 *
 * Allocates a new #TutGreeter.
 *
 * Return value: a new #TutGreeter.
 */
TutGreeter*
tut_greeter_new ()
{
    TutGreeter *greeter;

    greeter = g_object_new (TUT_GREETER_TYPE, NULL);
    return greeter;
}

/**
 * tut_greeter_greet:
 * @greeter: a #TutGreeter
 *
 * Prints a friendly greeting.
 *
 * Return value: nothing.
 */
void
tut_greeter_greet (TutGreeter *greeter)
{
    TutGreeterPrivate *priv;
    g_return_if_fail (greeter != NULL);

    priv = TUT_GREETER_GET_PRIVATE (greeter);

    printf ("Hello, %s!\n", priv->greetee);
}

