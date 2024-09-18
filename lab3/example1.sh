#!/usr/bin/bash
gcc -fsanitize=address -g example1.c -o example1
./example1