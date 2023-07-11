#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of array
 * @height: height of array
 *
 * Return: a pointer to a 2 dimensional array of integers.
 */
int **alloc_grid(int width, int height)
{
	int **avellin, a, b;
	int n = width * height;

	if (n <= 0)
		return (NULL);

	avellin = (int **)malloc(sizeof(int *) * height);
	if (avellin == NULL)
		return (NULL);

	for (a = 0; a < height; a++)
	{
		avellin[a] = (int *)malloc(sizeof(int) * width);
		if (avellin[a] == NULL)
		{
			for (a--; a >= 0; a--)
				free(avellin[a]);
			free(avellin);
			return (NULL);
		}
	}

	for (a = 0; a < height; a++)
		for (b = 0; b < width; b++)
			avellin[a][b] = 0;

	return (avellin);
}
