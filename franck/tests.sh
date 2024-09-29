#!/bin/sh
for var in $(seq 0 201)
do
    ./rush-02 $var | cat -e
done
