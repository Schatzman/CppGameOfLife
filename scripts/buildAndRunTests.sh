#!/bin/bash

set -ev
set -x
unzip -o test/gtest-1.7.0.zip -d test/gtest

if ! [ -d build ]; then
   mkdir build;
fi

cd build
cmake  -DCMAKE_CXX_FLAGS=-std=c++11 ..

makeArg=`grep -c ^processor /proc/cpuinfo`    

make -j$makeArg

./UnitTestRunner
