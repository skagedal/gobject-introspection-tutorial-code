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

#ifndef __TUT_GREETER_H__
#define __TUT_GREETER_H__

#include <glib.h>
#include <glib-object.h>

#define TUT_GREETER_TYPE		\
    (tut_greeter_get_type())
#define TUT_GREETER(o)			\
    (G_TYPE_CHECK_INSTANCE_CAST ((o), TUT_GREETER_TYPE, TutGreeter))
#define TUT_GREETER_CLASS(c)		\
    (G_TYPE_CHECK_CLASS_CAST ((c), TUT_GREETER_TYPE, TutGreeterClass))
#define TUT_IS_GREETER(o)		\
    (G_TYPE_CHECK_INSTANCE_TYPE ((o), TUT_GREETER_TYPE))
#define TUT_IS_GREETER_CLASS(c)		\
    (G_TYPE_CHECK_CLASS_TYPE ((c),  TUT_GREETER_TYPE))
#define TUT_GREETER_GET_CLASS(o)	\
    (G_TYPE_INSTANCE_GET_CLASS ((o), TUT_GREETER_TYPE, TutGreeterClass))

typedef struct _TutGreeter		TutGreeter;
typedef struct _TutGreeterPrivate	TutGreeterPrivate;
typedef struct _TutGreeterClass		TutGreeterClass;

struct _TutGreeter {
    GObject parent;
};

struct _TutGreeterClass {
    GObjectClass parent;
};

GType		tut_greeter_get_type	() G_GNUC_CONST;

TutGreeter*	tut_greeter_new		(void);

void		tut_greeter_greet	(TutGreeter *greeter);

#endif /* __TUT_GREETER_H__ */
