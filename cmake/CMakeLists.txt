# Specify the minimum CMake version required to build the project
cmake_minimum_required(VERSION 3.10)

# Define the project name and the languages used (C and C++)
project(RAYLIB_APP_MK_I C CXX)

# get the directory of the current source file, which is the project root
get_filename_component(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

# Recursively find all .cpp files in the 'src' directory and store them in the SOURCES variable
file(GLOB_RECURSE SOURCES "${PROJECT_ROOT}/src/*.cpp")

message("SOURCES: ${PROJECT_ROOT}")

# Set the directory where the executable binaries will be placed
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT}/bin/${CMAKE_SYSTEM_NAME})

# Set the directory where the shared libraries (.so/.dll) will be placed
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_ROOT}/bin/${CMAKE_SYSTEM_NAME})

# Set the directory where the static libraries (.a) will be placed
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_ROOT}/bin/${CMAKE_SYSTEM_NAME})

# Define the include directory for project-specific headers
set(PROJECT_INCLUDE_DIR ${PROJECT_ROOT}/src/includes)

# Check if the current operating system is Windows
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")

    # Specify the C compiler for Windows (MinGW)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)

    # Specify the C++ compiler for Windows (MinGW)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

    # Specify the order of library suffixes to look for (static .a first, then dynamic .dll)
    set(CMAKE_FIND_LIBRARY_SUFFIXES .a .dll)

    # Create an executable named 'RAYLIB_APP_MK_I_win' using the source files
    add_executable(RAYLIB_APP_MK_I_win ${SOURCES})

    # Set the include directories for the Windows build (where to find headers)
    target_include_directories(RAYLIB_APP_MK_I_win PRIVATE ${PROJECT_INCLUDE_DIR} /usr/x86_64-w64-mingw32/include)

    # Set the directories where the linker will look for libraries on Windows
    target_link_directories(RAYLIB_APP_MK_I_win PRIVATE /usr/x86_64-w64-mingw32/bin)

    # Link the 'raylib' library to the Windows executable
    target_link_libraries(RAYLIB_APP_MK_I_win PRIVATE raylib)

    # Add custom command to copy DLL files after the build
    add_custom_command(TARGET RAYLIB_APP_MK_I_win POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        /usr/x86_64-w64-mingw32/bin/libraylib.dll
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        /usr/x86_64-w64-mingw32/bin/libssp-0.dll
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    )

    # Add custom command to copy all files and directories recursively from 'resources' directory
    add_custom_command(TARGET RAYLIB_APP_MK_I_win POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_ROOT}/resources
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources
    )

else()
    # If not Windows, assume Linux-specific settings

    # Create an executable named 'RAYLIB_APP_MK_I_linux' using the source files
    add_executable(RAYLIB_APP_MK_I_linux ${SOURCES})

    # Set the include directories for the Linux build (where to find headers)
    target_include_directories(RAYLIB_APP_MK_I_linux PRIVATE ${PROJECT_INCLUDE_DIR} /usr/include)

    # Set the directories where the linker will look for libraries on Linux
    target_link_directories(RAYLIB_APP_MK_I_linux PRIVATE /usr/lib)

    # Link the 'raylib' library to the Linux executable
    target_link_libraries(RAYLIB_APP_MK_I_linux PRIVATE raylib)

    # Add custom command to copy all files and directories recursively from 'resources' directory
    add_custom_command(TARGET RAYLIB_APP_MK_I_linux POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_ROOT}/resources
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources
    )

endif()
