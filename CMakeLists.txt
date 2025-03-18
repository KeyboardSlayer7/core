cmake_minimum_required(VERSION 3.22.0)
project(KBSCore VERSION 0.0.1 LANGUAGES C)

set(
    SOURCES
    src/array.h
    src/sstring.h
)

option(BUILD_SHARED_LIBS "Build shared library" OFF)

if (BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCES})
endif()