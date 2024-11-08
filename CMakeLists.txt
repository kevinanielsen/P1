# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MovieProject)

# Add the executable, specifying both source files

add_executable(main main.c genres.h genres.c themes.h themes.c sadness.h sadness.c movie.h dataLoad.c dataLoad.h ratings.h ratings.c search.c search.h userProfiles.c userProfiles.h accountCheck.c accountCheck.h)


configure_file(${CMAKE_SOURCE_DIR}/IMDBTop250Movies.csv ${CMAKE_BINARY_DIR} COPYONLY)
