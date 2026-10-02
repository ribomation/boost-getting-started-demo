cmake_minimum_required(VERSION 3.28)
project(boost-getting-started LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)

# Point CMake at your Boost install with -DBoost_ROOT=<prefix>, unless it is
# installed in a system location (e.g. via apt) where it is found anyway.
find_package(Boost 1.92 CONFIG REQUIRED COMPONENTS program_options)

# Header-only: Boost::headers carries just the include path.
add_executable(moving-average src/moving-average.cxx)
target_link_libraries(moving-average PRIVATE Boost::headers)

# Compiled library: links libboost_program_options (static or shared,
# depending on how Boost was built).
add_executable(banner src/banner.cxx)
target_link_libraries(banner PRIVATE Boost::program_options)
