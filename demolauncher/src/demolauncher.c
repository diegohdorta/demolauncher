/* Copyright 2020 NXP Semiconductors
 *
 * Diego Dorta <diego.dorta@nxp.com>
 * BSD 3-Clause License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <gtk/gtk.h>
#include <stdlib.h>

#include "demolauncher.h"
#include "display.h"
#include "utils.h"

// TODO: USE TAB 8

int main(int argc, char *argv[])
{
        gtk_init(&argc,&argv);
        main_window = create_main_window();

        header = gtk_header_bar_new();

        // TODO: modularize this part.
        gtk_window_set_titlebar(GTK_WINDOW(main_window), header);
        gtk_window_set_title(GTK_WINDOW(main_window), "NXP Demo Launcher");
        // TODO: create defines
        gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header), TRUE);
        gtk_header_bar_set_decoration_layout(GTK_HEADER_BAR(header), "menu:minimize,close");

        toolbar = gtk_toolbar_new();
        vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

        button_license = gtk_button_new_with_label("LICENSE");
        gtk_header_bar_pack_end(GTK_HEADER_BAR(header), button_license);
        g_signal_connect(button_license, "clicked", G_CALLBACK (button_license_clicked), NULL); 
        // TODO: Create a new window for showing the license. Use this as example to create callbacks :)

        button_refresh = GTK_WIDGET(gtk_tool_button_new(NULL, NULL));
        gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(button_refresh), "view-refresh-symbolic");
        gtk_header_bar_pack_start(GTK_HEADER_BAR(header), button_refresh);
        // TODO: Implement refresh button

        button_home = GTK_WIDGET(gtk_tool_button_new(NULL, NULL));
        gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(button_home), "go-home");
        gtk_toolbar_insert(GTK_TOOLBAR(toolbar), (GtkToolItem *)button_home, -1);
        // TODO: Implement home button function

        button_fullscreen = GTK_WIDGET(gtk_tool_button_new(NULL, NULL));
        gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(button_fullscreen), "view-fullscreen");
        gtk_toolbar_insert(GTK_TOOLBAR(toolbar), (GtkToolItem *)button_fullscreen, -1);
        // TODO: Implement full screen button function

        hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        sidebar = gtk_stack_sidebar_new();
        gtk_box_pack_start(GTK_BOX(hbox), sidebar, FALSE, FALSE, 0);

        stack = gtk_stack_new();
        gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_UP);
        gtk_stack_sidebar_set_stack(GTK_STACK_SIDEBAR(sidebar), GTK_STACK(stack));

        gtk_box_pack_start(GTK_BOX(hbox), gtk_separator_new(GTK_ORIENTATION_VERTICAL), FALSE, FALSE, 0);                               
        gtk_box_pack_start(GTK_BOX(hbox), stack, TRUE, TRUE, 0);

        widget = gtk_image_new_from_icon_name("face-angry", GTK_ICON_SIZE_MENU);
        // TODO: Change icons to a more appropriate symbol.
        gtk_image_set_pixel_size(GTK_IMAGE(widget), 150);
        gtk_stack_add_named(GTK_STACK(stack), widget, pages[0]);
        gtk_container_child_set(GTK_CONTAINER(stack), widget, "title", pages[0], NULL);

        widget = gtk_image_new_from_icon_name("face-sick", GTK_ICON_SIZE_MENU);
        gtk_image_set_pixel_size(GTK_IMAGE(widget), 250);
        gtk_stack_add_named(GTK_STACK(stack), widget, pages[1]);
        gtk_container_child_set(GTK_CONTAINER(stack), widget, "title", pages[1], NULL);

        widget = gtk_image_new_from_icon_name("face-laugh", GTK_ICON_SIZE_MENU);
        gtk_image_set_pixel_size(GTK_IMAGE(widget), 350);
        gtk_stack_add_named(GTK_STACK(stack), widget, pages[2]);
        gtk_container_child_set(GTK_CONTAINER(stack), widget, "title", pages[2], NULL);

        gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 0);   
        gtk_box_pack_start(GTK_BOX(vbox), bar, FALSE, FALSE, 0);   
        gtk_box_pack_start(GTK_BOX(vbox), gtk_separator_new(GTK_ORIENTATION_HORIZONTAL), FALSE, FALSE, 0);                               
        gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);                                  
        gtk_container_add(GTK_CONTAINER(main_window), vbox);                                                             

        g_signal_connect_swapped(G_OBJECT(main_window), "destroy", G_CALLBACK(exit), 0);
        gtk_widget_show_all(main_window);
        gtk_main();

        return EXIT_SUCCESS;
}
