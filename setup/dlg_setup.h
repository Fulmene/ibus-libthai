/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 *  Copyright (C) 2012 Theppitak Karoonboonyanan <theppitak@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef __DLG_SETUP_H__
#define __DLG_SETUP_H__

#include "ibus_config.h"
#include <gtk/gtk.h>

GtkWidget *ibus_libthai_setup_dialog_new ();

void ibus_libthai_setup_set_values (const GtkDialog *dlg,
                                    const IBusLibThaiSetupOptions *opt);
void ibus_libthai_setup_get_values (const GtkDialog *dlg,
                                    IBusLibThaiSetupOptions *opt);

#endif /* __DLG_SETUP_H__ */

/*
vi:ts=2:nowrap:ai:expandtab
*/
