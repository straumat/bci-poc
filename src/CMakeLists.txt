cmake_minimum_required(VERSION 2.6)

SET(CMAKE_CXX_COMPILER g++)

project(main)

include_directories([SYSTEM] "${PROJECT_SOURCE_DIR}" "lib")

file(GLOB_RECURSE SOURCES
${PROJECT_SOURCE_DIR}/main.cpp
)

add_definitions(-D_SPIRDEBUG=0)

SET(CMAKE_CXX_FLAGS "-m32 -std=c++03 -ansi -fpermissive -fshort-wchar -fno-rtti -W")
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
SET(CMAKE_CXX_FLAGS_RELEASE " ")

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
link_directories(${GLUT_LIBRARIES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
link_directories(${OPENGL_LIBRARIES})

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})
link_directories(${X11_LIBRARIES})

find_package(Threads REQUIRED)
link_directories(${THREADS_LIBRARIES})


link_directories(
	${PROJECT_SOURCE_DIR}/../lib
)

add_executable(main ${SOURCES})
target_link_libraries(main inspector spirmemory neo4j-client pthread X11 dl)