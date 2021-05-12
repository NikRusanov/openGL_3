#!/bin/bash +x

#build_dir="./build"
#
#if [[ -d $build_dir ]]; then
#    rm -Rf $build_dir
#fi
#
#meson build
#ninja -C ./build
g++ -o opengl main.cpp src/*.cpp -lglut -lGLU -lGL -lglfw
