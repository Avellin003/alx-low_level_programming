#include "function_pointers.h"
#include <stdio.h>
/**
  * int_index - function indexes
  * @array: pointer argument
  * @size: argument
  * @cmp: function pointer
  * Return: -1
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
