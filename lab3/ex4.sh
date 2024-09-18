#!/usr/bin/bash
gcc -fsanitize=address -g ex4.c -o ex4 -lm
./ex4