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

#spdlog
set(SPDLOG_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_DIR}/spdlog/include)
#

#glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${VENDOR_DIR}/glfw)
set(GLFW_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_DIR}/glfw/include)
#

#glad
add_subdirectory(${VENDOR_DIR}/glad)
set(GLAD_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_DIR}/glad/include)
#

#

set(INCLUDE_DIRECTORIES ${SPDLOG_INCLUDE})
set(LIBS_DIRECTORIES)
set(LIBS glfw glad)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${INCLUDE_DIRECTORIES}
                           ${GLAD_INCLUDE})
target_link_libraries(${PROJECT_NAME} ${LIBS})
