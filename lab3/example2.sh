#!/usr/bin/bash
gcc -fsanitize=address -g example2.c -o example2
./example2