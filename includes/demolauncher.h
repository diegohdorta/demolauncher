/* Copyright 2020 NXP Semiconductors
 *   
 * SPDX-License-Identifier: BSD-3-Clause
 * Diego Dorta <diego.dorta@nxp.com>
 */

#ifndef DEMO_LAUNCHER_H_
#define DEMO_LAUNCHER_H_
 
GtkWidget *main_window = NULL;
GtkWidget *sidebar;
GtkWidget *stack;
GtkWidget *outbutton;
GtkWidget *hbox;
GtkWidget *vbox;
GtkWidget *message_label;
GtkWidget *header;
GtkWidget *widget;
GtkWidget *content_area;
GtkWidget *toolbar;
GtkWidget *bar;
GtkWidget *button_refresh;
GtkWidget *button_license;
GtkWidget *button_home;
GtkWidget *button_fullscreen;

const char *c = NULL;	
const char *pages[] = { "Multimedia",
                        "eIQ Machine Learning",
                        "Unit Tests",
                        NULL
};

#endif /* DEMO_LAUNCHER_H_ */
