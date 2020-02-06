# Copyright 2019 NXP Semiconductors
#    
# SPDX-License-Identifier: BSD-3-Clause
# Diego Dorta <diego.dorta@nxp.com>

project(demolauncher)
cmake_minimum_required(VERSION 3.9)
cmake_policy(VERSION 3.9)

set(PROJECT_DESCRIPTION "Graphical User Interface for Launching i.MX Demos")
message(STATUS "Running CMake for ${PROJECT_NAME} (${PROJECT_DESCRIPTION})")

project(demolauncher C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall \
                                        -Wextra \
                                        -Werror \
                                        -fsanitize=leak \
                                        -fno-omit-frame-pointer \
                                        -g3 \
                                        -Ofast \
                                        -std=c++11")
include_directories(includes)
add_subdirectory(demolauncher)
