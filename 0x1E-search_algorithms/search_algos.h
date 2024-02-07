#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*0-linear.c*/
int linear_search(int *array, size_t size, int value);
/*1-binary.c*/
int binary_search(int *array, size_t size, int value);
/*100-jump.c*/
int jump_search(int *array, size_t size, int value);
/*102-interpolation.c*/
int interpolation_search(int *array, size_t size, int value);
#endif
