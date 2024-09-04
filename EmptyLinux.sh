#!/bin/bash

# Output directory
target="Targets/$1"

# Activate Python environment (uncomment if needed)
# source ~/python/bin/activate

# Install Conan dependencies
conan install . --install-folder "$target" --build=missing -s build_type="$1" \
    -c tools.system.package_manager:sudo=True \
    -c tools.system.package_manager:mode=install



