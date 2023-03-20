#!/bin/bash
gcc -c *.c
gcc -shared -libdynamic.so *.o
