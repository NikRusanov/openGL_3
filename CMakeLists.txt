cmake_minimum_required(VERSION 3.17)
project(opengl_lab3)

set(CMAKE_CXX_STANDARD 17)


include_directories(.)


add_executable(${PROJECT_NAME}
        src/icosahedron.cpp
        src/Utils.cpp
        main.cpp )
target_link_libraries(${PROJECT_NAME}
        -lglut
        -lGLU
        -lGL)
