cmake_minimum_required (VERSION 3.8)

set (CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/Install" CACHE PATH "" FORCE)

project (Snake)

add_subdirectory(src)
