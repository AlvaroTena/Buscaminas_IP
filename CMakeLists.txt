cmake_minimum_required(VERSION 3.10)
project(Buscaminas C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(SOURCES
    ajustes.c
    jugadas.c
    main.c
    salida.c
    saves.c
    tablero.c
)

add_executable(Buscaminas ${SOURCES})

