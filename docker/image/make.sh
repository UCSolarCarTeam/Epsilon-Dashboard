#!/bin/bash

# Copy and cleanup directory
cp -r ${DIR_IN}/* .
rm -rf ./build

# Make
cd src/
make distclean
qmake
make -j4
mkdir -p ${DIR_OUT}
cd ..

# Copy build results out of container
cp -r ./build/* ${DIR_OUT}
