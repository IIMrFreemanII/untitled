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

##spdlog header only
set(SPDLOG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_DIR}/spdlog/include)
##

##glm header only
set(GLM_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_DIR}/glm)
##

##glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${VENDOR_DIR}/glfw)

set(GLFW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_DIR}/glfw/include)
set(GLFW_LIB glfw)
##

##vk-bootstrap
##add_subdirectory(${VENDOR_DIR}/vk-bootstrap)
##

##vulkan
set(VULKAN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_DIR}/vulkan/include)
set(VULKAN_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${VENDOR_DIR}/vulkan/lib)
set(VULKAN_LIB libvulkan.1.dylib libvulkan.1.3.211.dylib)
##

#

set(INCLUDE_DIR
    ${SPDLOG_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${VULKAN_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR})

set(LIB_DIR
    ${VULKAN_LIB_DIR})

set(LIB
    ${GLFW_LIB}
    ${VULKAN_LIB})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${LIB_DIR})
target_link_libraries(${PROJECT_NAME} ${LIB})
