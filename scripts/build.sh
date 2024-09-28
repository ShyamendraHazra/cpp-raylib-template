#!/bin/bash

source ./scripts/globals.sh

echo -e "Cleaning previous builds and binaries :: \n"

./scripts/clean.sh

echo -e "Building binaries :: \n"

echo -e "Building binary for Linux :: \n"

cmake -S "$CMAKE_DIR" -B "$BUILD_DIR/Linux"

echo -e "Building binary for Windows :: \n"

cmake -DCMAKE_TOOLCHAIN_FILE=mingw-toolchain.cmake -S "$CMAKE_DIR" -B "$BUILD_DIR/Windows"
