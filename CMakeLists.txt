# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MovieProject)

# Add the executable, specifying both source files
add_executable(main main.c genres.h themes.h)
