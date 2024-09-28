#!/bin/bash

source ./scripts/globals.sh

echo -e "\n:: Making binary for Linux ::\n"

cmake --build "$BUILD_DIR/Linux"

echo -e "\n:: Making binary for Windows ::\n"

cmake --build "$BUILD_DIR/Windows"