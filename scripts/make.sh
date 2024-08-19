#!/bin/bash
echo -e "Fetching libraries :: \n"

mkdir -p lib bin bin/Windows bin/Linux    

echo copying libraylib.dll and libssp-0.dll to lib folder

cp /usr/x86_64-w64-mingw32/bin/libraylib.dll lib/
cp /usr/x86_64-w64-mingw32/bin/libssp-0.dll lib/

echo -e "\n:: Making binary for Linux ::\n"

make -C build/linux

echo -e "\n:: Making binary for Windows ::\n"

make -C build/windows
# make

echo -e "Copying fetched library file as dependency to bin folder  :: \n"

cp lib/* bin/Windows
