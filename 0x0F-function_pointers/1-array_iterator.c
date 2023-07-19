#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - function that executes
 * @action: function pointer
 * @size: size of array
 * @array: array
 * Return: nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t n;

	if (array && action)
	{
		n = 0;
		while (n < size)
		{
			action(array[n]);
			n++;
		}
	}
}
