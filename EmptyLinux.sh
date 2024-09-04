# !/bin/bash

# output directory
target="Targets/$1"

# activate python env
source ~/empy/bin/activate
# install conan dependencies
conan install. --install-folder $target --build
missing -s build_type=$1-c
tools.system.package_manager:sudo=True -c
tools.system.package_manager:mode=install
# generate make build files
cmake -S . -B Starget
-DCMAKE_BUILD_TYPE=$1
-DCMAKE_TOOLCHAIN_FILE="conanbuildinfo.cmake"

# compile make build files
make --build $target --config $1

