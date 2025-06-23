#!/bin/bash

# Clean and build
make clean
make

# Run analyzer on all test files
for testfile in testes/*.txt; do
    echo
    echo "======================================"
    echo "Running test: $testfile"
    echo "--------------------------------------"
    ./analisador < "$testfile"
    echo "======================================"
    echo
    echo
    echo
done