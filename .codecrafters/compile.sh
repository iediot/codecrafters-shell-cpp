#!/bin/sh
#
# This script is used to compile your program on CodeCrafters
#
# This runs before .codecrafters/run.sh
#
# Learn more: https://codecrafters.io/program-interface

set -e # Exit on failure

# Only hand CMake the vcpkg toolchain when vcpkg is actually available --
# passing an empty VCPKG_ROOT points at "/scripts/buildsystems/vcpkg.cmake",
# which fails the configure step (e.g. on a plain macOS checkout).
if [ -n "${VCPKG_ROOT}" ] && [ -f "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" ]; then
  cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
else
  cmake -B build -S .
fi
cmake --build ./build
