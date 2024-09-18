#!/usr/bin/bash
gcc -fsanitize=address -g ex1.c -o ex1
./ex1