# --------------------- #
# (C) 2020 madoodia.com #
# All Rights Reserved.  #
# --------------------- #

cmake_minimum_required(VERSION 3.3)

project($ENV{TARGET_NAME}_prj CXX)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
)


include_directories(../Common)

add_executable($ENV{TARGET_NAME} ${SOURCES})

# OpenCL
# find_package(OpenCL REQUIRED)
# include_directories(${OPENCL_INCLUDE_DIRS})
# target_link_libraries($ENV{TARGET_NAME} ${OPENCL_LIBRARIES} OpenCL)

# OR
include_directories($ENV{OPENCL_LOCATION}/include)
target_link_libraries($ENV{TARGET_NAME} $ENV{OPENCL_LOCATION}/lib OpenCL)


# # # OpenGL
# find_package(OpenGL REQUIRED)
# # target_link_libraries($ENV{TARGET_NAME} ${OPENGL_LIBRARIES})

# # GLEW
# find_package(GLEW REQUIRED) # if you install GLEW on linux
# include_directories(${GLEW_INCLUDE_DIRS})
# # target_link_libraries($ENV{TARGET_NAME} ${GLEW_LIBRARIES})
