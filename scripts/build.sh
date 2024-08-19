#!/bin/bash

echo -e "Cleaning previous builds and binaries :: \n"

./scripts/clean.sh

mkdir -p build build/linux build/windows

cmake -S . -B build/linux

cmake -DCMAKE_TOOLCHAIN_FILE=mingw-toolchain.cmake -S . -B build/windows
