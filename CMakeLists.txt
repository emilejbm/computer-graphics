cmake_minimum_required(VERSION 3.10)
project(cs334_beginner)

set(CMAKE_CXX_STANDARD 14)

set(FLTK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/deps/fltk-master/build)
set(OpenGL_GL_PREFERENCE LEGACY)


find_package(FLTK REQUIRED NO_MODULE)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)


include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)
include_directories(deps/libtiff-master/build/libtiff)
include_directories(deps/libtiff-master/libtiff)

# src
file(GLOB
        SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        )

add_executable(cs334_beginner ${SOURCE_FILES} src/tm.cpp src/CubeMap.cpp includes/CubeMap.h)
if (APPLE)
    target_link_libraries(cs334_beginner "-framework cocoa")
endif (APPLE)

target_include_directories(cs334_beginner PUBLIC  ${PROJECT_SOURCE_DIR}/deps/fltk-master/ ${PROJECT_SOURCE_DIR}/deps/fltk-master/build)
target_link_libraries(cs334_beginner fltk fltk_gl OpenGL::GL GLUT::GLUT tiff)