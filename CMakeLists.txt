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
    message(STATUS "Windows build detected - using raylib from C:\\raylib\\raylib\\src")
    
    # Set raylib include directory
    set(RAYLIB_INCLUDE_DIR "C:/raylib/raylib/src")
    include_directories(${RAYLIB_INCLUDE_DIR})
    
    # Set raylib library path
    set(RAYLIB_LIB "C:/raylib/raylib/src/libraylib.a")
    
    # Check if raylib files exist
    if(NOT EXISTS ${RAYLIB_INCLUDE_DIR}/raylib.h)
        message(WARNING "raylib.h not found at ${RAYLIB_INCLUDE_DIR}/raylib.h")
    endif()
    if(NOT EXISTS ${RAYLIB_LIB})
        message(WARNING "libraylib.a not found at ${RAYLIB_LIB}")
    endif()
    
    # Check compiler compatibility
    if(MSVC)
        message(WARNING "MSVC compiler detected, but libraylib.a is built with MinGW.")
        message(WARNING "This will cause linking errors. Solutions:")
        message(WARNING "1. Install MinGW and use it as compiler (e.g., cmake -G \"MinGW Makefiles\" ...)")
        message(WARNING "2. Build raylib with MSVC and update the library path.")
    endif()
    
    # Link with raylib and required Windows libraries
    target_link_libraries(pac-man ${RAYLIB_LIB})
    target_link_libraries(pac-man opengl32 gdi32 winmm)
    
    # Note: Source code POSIX issues have been fixed (unistd.h removed, getline qualified)
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
