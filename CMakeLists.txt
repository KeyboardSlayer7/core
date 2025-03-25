cmake_minimum_required(VERSION 3.22.0)
project(KBSCore VERSION 0.0.1 LANGUAGES C)

set(
    SOURCES
    include/array.h
    include/sstring.h
    include/arena.h
    include/hex.h
    src/array.c
    src/sstring.c
    src/arena.c
    src/hex.c
)

option(BUILD_SHARED_LIBS "Build shared library" OFF)

# add_subdirectory(${CMAKE_SOURCE_DIR}/src)

if (BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED ${SOURCES})
else()
    add_library(${PROJECT_NAME} STATIC ${SOURCES})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)