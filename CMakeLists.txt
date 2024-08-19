cmake_minimum_required(VERSION 3.10)
project(MyProject C CXX)

# Add the source files using glob
file(GLOB_RECURSE SOURCES "src/*.c")

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME})

# Determine platform-specific settings
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Windows specific settings (MinGW)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
    set(CMAKE_FIND_LIBRARY_SUFFIXES .a .dll)

    # Add the Windows executable
    add_executable(MyProject_win ${SOURCES})

    # Specify MinGW paths for include and lib
    target_include_directories(MyProject_win PRIVATE /usr/x86_64-w64-mingw32/include)
    target_link_directories(MyProject_win PRIVATE /usr/x86_64-w64-mingw32/lib)
    target_link_libraries(MyProject_win PRIVATE raylib)

else()
    # Linux specific settings
    include_directories(/usr/include)
    link_directories(/usr/lib)

    # Add the Linux executable
    add_executable(MyProject_linux ${SOURCES})

    # Link with installed Raylib on Linux
    target_include_directories(MyProject_linux PRIVATE /usr/include)
    target_link_directories(MyProject_linux PRIVATE /usr/lib)
    target_link_libraries(MyProject_linux PRIVATE raylib)
endif()
