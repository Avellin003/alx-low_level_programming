#include "main.h"

/**
 *swap_int - used to swap functions of two integers
 *@a: integer to be swapped
 *@b: integer to be swapped
 *return: 1 when success else 0
 */

void swap_int(int *a, int *b)
{
	int avellin = *a;
	*a = *b;
	*b = avellin;
}
