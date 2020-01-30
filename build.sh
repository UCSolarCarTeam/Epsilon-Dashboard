#!/bin/bash

if [ ! -d ./build ]; then
  mkdir ./build
fi
cd ./build

conan install .. --build=outdated -s compiler.libcxx="libstdc++11"

qmake ../src
make qmake_all
make -j4
