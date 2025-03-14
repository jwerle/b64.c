cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME b64c)
project(${PROJECT_NAME} LANGUAGES C)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_library(${PROJECT_NAME}
    buffer.c
    decode.c
    encode.c
)

target_include_directories(${PROJECT_NAME} INTERFACE .)
