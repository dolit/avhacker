#!/bin/sh
rm -rf build
if [ -d "build" ]; then
    echo "build directory must be deleted!"
    exit 1
fi
mkdir build
cd build
cmake -G"Unix Makefiles" ..
