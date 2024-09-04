#!/bin/bash

# Check if the build type is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <build_type>"
    echo "Available build types: Debug, Release, RelWithDebInfo, MinSizeRel"
    exit 1
fi

BUILD_TYPE="$1"
TARGET_DIR="include" # Replace with your actual target directory

conan install . -of="$TARGET_DIR" --build=missing -s build_type="$BUILD_TYPE" \
    -c tools.system.package_manager:sudo=True \
    -c tools.system.package_manager:mode=install \
    -g CMakeToolchain -g CMakeDeps




