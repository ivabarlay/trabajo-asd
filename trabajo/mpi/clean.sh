#!/bin/bash
SRC_RESULTS="./results"

# Cleans result directory and all its files

rm -rf ${SRC_RESULTS}

# Clean compiled files with make

make clean
