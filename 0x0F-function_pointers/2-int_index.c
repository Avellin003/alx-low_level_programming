#include "function_pointers.h"
#include <stdio.h>
/**
 * cmp - function that compares
 * @size: number of elements in array
 * return: returns 0 for unsuccess and -1 for a negative number
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (i < size)
			{
				if (cmp(array[i]))
					return (i);

				i++;
			}
		}
	}

	return (-1);
}
