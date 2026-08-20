cmake_minimum_required(VERSION 3.20)

project(shell-starter-cpp LANGUAGES CXX)

# Default to a Release build when the user doesn't pick one (single-config
# generators like Makefiles/Ninja leave CMAKE_BUILD_TYPE empty otherwise).
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.hpp)

add_executable(shell ${SOURCE_FILES})

# --- readline (optional) ----------------------------------------------------
# Linux distros ship it on the default search path; on macOS the system only
# provides the libedit compatibility stub, so prefer the Homebrew keg (which is
# keg-only and therefore invisible to the compiler unless we point at it).
if(APPLE)
    find_program(BREW_EXECUTABLE brew)
    if(BREW_EXECUTABLE)
        execute_process(
            COMMAND ${BREW_EXECUTABLE} --prefix readline
            OUTPUT_VARIABLE READLINE_BREW_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
            ERROR_QUIET)
    endif()
    list(APPEND READLINE_HINT_DIRS
        ${READLINE_BREW_PREFIX}
        /opt/homebrew/opt/readline
        /usr/local/opt/readline)
endif()

find_path(READLINE_INCLUDE_DIR readline/readline.h
    HINTS ${READLINE_HINT_DIRS}
    PATH_SUFFIXES include)
find_library(READLINE_LIBRARY readline
    HINTS ${READLINE_HINT_DIRS}
    PATH_SUFFIXES lib)

if(READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
    message(STATUS "Found readline: ${READLINE_LIBRARY}")
    target_include_directories(shell PRIVATE ${READLINE_INCLUDE_DIR})
    target_link_libraries(shell PRIVATE ${READLINE_LIBRARY})
    target_compile_definitions(shell PRIVATE HAVE_READLINE=1)
else()
    # The shell currently drives the terminal through termios directly, so this
    # is not fatal -- guard any readline usage with #ifdef HAVE_READLINE.
    message(STATUS "readline not found; building without it")
endif()
