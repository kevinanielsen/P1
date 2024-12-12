# Minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(MovieProject)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Source directories
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Add subdirectories to organize functionality
file(GLOB_RECURSE ACCOUNT_FILES ${SRC_DIR}/account/*.c)
file(GLOB_RECURSE DATA_FILES ${SRC_DIR}/data/*.c)
file(GLOB_RECURSE GENRES_FILES ${SRC_DIR}/genres/*.c)
file(GLOB_RECURSE MOODS_FILES ${SRC_DIR}/moods/*.c)
file(GLOB_RECURSE MOVIES_FILES ${SRC_DIR}/movies/*.c)
file(GLOB_RECURSE SEARCH_FILES ${SRC_DIR}/search/*.c)
file(GLOB_RECURSE THEMES_FILES ${SRC_DIR}/themes/*.c)
file(GLOB MAIN_FILE ${SRC_DIR}/main.c)

# Combine all source files
set(SOURCE_FILES
    ${ACCOUNT_FILES}
    ${DATA_FILES}
    ${GENRES_FILES}
    ${MOODS_FILES}
    ${MOVIES_FILES}
    ${THEMES_FILES}
    ${SEARCH_FILES}
    ${MAIN_FILE}
)

# Add executable
add_executable(MovieProject ${SOURCE_FILES})

# Include directories
target_include_directories(MovieProject PRIVATE
    ${SRC_DIR}/account
    ${SRC_DIR}/data
    ${SRC_DIR}/genres
    ${SRC_DIR}/moods
    ${SRC_DIR}/movies
    ${SRC_DIR}/search
    ${SRC_DIR}/themes
)

# Copy resources to the build directory
configure_file(${CMAKE_SOURCE_DIR}/resources/IMDBTop250Movies.csv ${CMAKE_BINARY_DIR}/IMDBTop250Movies.csv COPYONLY)
