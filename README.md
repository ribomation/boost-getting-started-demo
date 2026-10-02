# Getting started with Boost — demo

Runnable companion code for the article
[*Kom igång med Boost*](https://www.ribomation.se/blog/2026/kom-igang-med-boost/) (in Swedish).

Built and run with **Boost 1.92.0**, **GCC 16.1** and **CMake 4.2** on Ubuntu 26.04.

## Build & run

Against an installed Boost (system package, vcpkg, Conan or your own build):

```bash
cmake -S . -B build -G Ninja -DBoost_ROOT=$HOME/Libs/Boost/latest   # omit Boost_ROOT if Boost is in a system location
cmake --build build

echo "3 5 7 9 11" | ./build/moving-average 3
./build/banner -n 2 --upper "hello boost"
./build/banner --help
```

Or let CMake download and build Boost itself (no Boost install needed, ~100 MB download):

```bash
cmake -S fetch-content -B fetch-content/build -G Ninja
cmake --build fetch-content/build
./fetch-content/build/banner "fetched"
```

## Contents

| File | What it shows |
|---|---|
| [`src/moving-average.cxx`](src/moving-average.cxx) | Header-only Boost: a sliding window with `boost::circular_buffer`, linked against `Boost::headers` |
| [`src/banner.cxx`](src/banner.cxx) | A compiled Boost library: command-line parsing with Boost.Program_options, linked statically |
| [`CMakeLists.txt`](CMakeLists.txt) | `find_package(Boost CONFIG ...)` against an installed Boost |
| [`fetch-content/CMakeLists.txt`](fetch-content/CMakeLists.txt) | The same `banner`, with Boost fetched and built via `FetchContent` |
