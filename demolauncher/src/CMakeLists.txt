# Copyright 2019 NXP Semiconductors
#    
# SPDX-License-Identifier: BSD-3-Clause
# Diego Dorta <diego.dorta@nxp.com>

include_directories(${GTK3_INCLUDE_DIRS})

include_directories(include)

link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(demolauncher demolauncher.c utils.c display.c)
# TODO: Found a more sophisticated way than this.

target_link_libraries(demolauncher ${GTK3_LIBRARIES})
