#!/bin/bash -xe
#
# A _very_ rudimentary test script for coffee-fs
#
#

function abort {
    echo "Test failed!"
    exit 1
}

make clean
make
OUTPUT=$(build/coffee "this is the input" | tail -n1)
[[ "this is the input" == "$OUTPUT" ]] || abort
echo "Test passed!"

