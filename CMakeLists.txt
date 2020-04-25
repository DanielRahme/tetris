cmake_minimum_required(VERSION 3.13.0)

# The project name, version and languages
project(Hello VERSION 1.0 LANGUAGES CXX)

# NCurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# The library files
add_library(LibSources 
    src/functions.cpp 
    )
target_include_directories(LibSources PUBLIC inc)
target_compile_features(LibSources PUBLIC cxx_std_17)

# The executable target
set(TargetName hello)
add_executable(${TargetName} src/hello.cpp)

# Set the language standard to C++17 for target
set_target_properties(${TargetName} PROPERTIES  CXX_STANDARD 17)

# Compiler flags for target
target_compile_options(${TargetName} PRIVATE
    -lncurses
    -O3
    -Werror
    -Wall
    -Wextra
    -Wpedantic
    )

target_link_libraries(${TargetName} PRIVATE LibSources ${CURSES_LIBRARIES})
#target_link_libraries(${TargetName} ${CURSES_LIBRARIES})
