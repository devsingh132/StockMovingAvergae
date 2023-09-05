#!/bin/bash
cd "$(dirname "$0")"
mkdir -p Release && cd Release
cmake ..

if make -j4
then
   echo Build successful
else
   echo Build failed, exiting!
   exit 1
fi
