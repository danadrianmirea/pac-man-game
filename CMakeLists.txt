cmake_minimum_required(VERSION 3.10)
project(pac-man LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform-specific definitions
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    # Windows doesn't have unistd.h, but the code might not actually need it
    # We'll create a dummy unistd.h if needed (commented out as it's better to fix source)
    # add_definitions(-DNO_UNISTD_H)
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/game.cpp
    src/utils.cpp
    src/pixels.cpp
    src/Map/Map.cpp
    src/Key/Key.cpp
    src/PacMan/PacMan.cpp
    src/PacMan/Cpu.cpp
)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Create executable
add_executable(pac-man ${SOURCES})

# Platform-specific configuration
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # Linux-specific settings
    set(RAYLIB_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/libraylib_linux.a)
    target_link_libraries(pac-man ${RAYLIB_LIB})
    target_link_libraries(pac-man m pthread dl rt X11)
    
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    # macOS-specific settings
    set(RAYLIB_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/libraylib_macos.a)
    target_link_libraries(pac-man ${RAYLIB_LIB})
    target_link_libraries(pac-man
        "-framework CoreVideo"
        "-framework IOKit"
        "-framework Cocoa"
        "-framework GLUT"
        "-framework OpenGL"
    )
    
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Windows-specific settings
    message(STATUS "Windows build detected - raylib library not provided")
    message(STATUS "For Windows build, you need to:")
    message(STATUS "1. Download raylib for Windows from https://www.raylib.com/")
    message(STATUS "2. Link with raylib.lib instead of static library")
    message(STATUS "3. Fix POSIX headers in source code (unistd.h, getline)")
    # Try to find raylib if installed
    find_package(raylib QUIET)
    if(raylib_FOUND)
        target_link_libraries(pac-man raylib)
    else()
        message(WARNING "raylib not found, build will likely fail")
    endif()
endif()

# Copy assets to build directory (optional)
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY maps DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY sounds DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Add build instructions similar to Makefile targets
add_custom_target(run
    COMMAND pac-man
    DEPENDS pac-man
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running pac-man game"
)

# Note: CMake already provides 'clean' target when using build system generators
# The 're' target (rebuild) can be achieved with '--clean-first' build option
# or by manually running clean then build
