#!/bin/bash

echo -e "\n:: Making binary for Linux ::\n"

make -C build/Linux

echo -e "\n:: Making binary for Windows ::\n"

make -C build/Windows