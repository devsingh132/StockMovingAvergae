#!/bin/bash
cd "$(dirname "$0")"
mkdir -p Debug && cd Debug
cmake -DCMAKE_BUILD_TYPE=DEBUG ..

if make -j4
then
   echo Build successful
else
   echo Build failed, exiting!
   exit 1
fi
