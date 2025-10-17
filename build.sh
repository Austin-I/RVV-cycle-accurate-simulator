#!/bin/bash

BUILD_PATH="build"

rm -rf build

echo "Building mac"

cmake -B $BUILD_PATH
cmake --build $BUILD_PATH