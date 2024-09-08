#!/bin/bash

echo -e "Cleaning previous builds and binaries :: \n"

./scripts/clean.sh

echo -e "Building binaries :: \n"

echo -e "Building binary for Linux :: \n"

cmake -S cmake -B build/Linux

echo -e "Building binary for Windows :: \n"

cmake -DCMAKE_TOOLCHAIN_FILE=mingw-toolchain.cmake -S cmake -B build/Windows
