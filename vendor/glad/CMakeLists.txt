cmake_minimum_required(VERSION 3.22)

project(glad LANGUAGES C)

set(SOURCE_FILES
        src/glad.c
        include/glad/glad.h
        include/KHR/khrplatform.h
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)