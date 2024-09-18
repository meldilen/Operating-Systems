#!/usr/bin/bash
gcc -fsanitize=address -g ex2.c -o ex2 -lm
./ex2