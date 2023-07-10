#!/bin/bash
gcc -Wall -pedantic -Wextra -Werror .*c
ar rc liball.a *.o
