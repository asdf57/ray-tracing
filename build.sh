#!/bin/sh

if [ "$1" = "tests" ]; then
    cmake -S . -B build -DBUILD_TESTS=ON
    cmake --build build
    cd build && ctest --output-on-failure
else
    cmake -S . -B build
    cmake --build build
fi
