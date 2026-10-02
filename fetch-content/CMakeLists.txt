cmake_minimum_required(VERSION 3.28)
project(banner-fetchcontent LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
set(BOOST_INCLUDE_LIBRARIES program_options)   # configure & build only what we need
set(BUILD_SHARED_LIBS OFF)                     # link Boost statically
FetchContent_Declare(Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.92.0/boost-1.92.0-cmake.tar.xz
    URL_HASH SHA256=9bed76128d4e46755dbe818487788c6fceb6f72b378f4daa49b7e1e600d9088d
    DOWNLOAD_EXTRACT_TIMESTAMP ON
    EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(Boost)

add_executable(banner ../src/banner.cxx)
target_link_libraries(banner PRIVATE Boost::program_options)
