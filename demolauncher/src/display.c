/* Copyright 2020 NXP Semiconductors
 *   
 * SPDX-License-Identifier: BSD-3-Clause
 * Diego Dorta <diego.dorta@nxp.com>
 */

#include <gtk/gtk.h>

GtkWidget *create_main_window(void)
{
        GtkWidget *w = NULL;
        w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_resizable(GTK_WINDOW(w), FALSE);
        gtk_widget_set_size_request(w, 1280, 720);
        // TODO: create defines.
        
        return w;
}
