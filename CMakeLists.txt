cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES
    src/main.cpp
    src/log.cpp
    src/log.h
    src/application.cpp
    src/application.h)

# Vendors
set(VENDOR_DIR vendor)
set(SPDLOG_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_DIR}/spdlog/include)
#

set(INCLUDE_DIRECTORIES ${SPDLOG_INCLUDE})
set(LIBS_DIRECTORIES)
set(LIBS)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRECTORIES})
