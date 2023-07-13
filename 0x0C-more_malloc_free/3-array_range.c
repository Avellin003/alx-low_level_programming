#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * *array_range - creates an array of integers
 * @min: minimum range
 * @max: maximum range
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int *avellin;
	int a, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	avellin = malloc(sizeof(int) * size);

	if (avellin == NULL)
		return (NULL);

	for (a = 0; min <= max; a++)
		avellin[a] = min++;

	return (avellin);
}
