#!/bin/bash
cd "$(dirname "$0")"
today=`date "+%Y_%m_%d"`
FILE_NAME=$1
SIM_CONFIG=$2
./Release/simulator "$FILE_NAME" "$SIM_CONFIG" > logs/${today}.log 2>&1 &