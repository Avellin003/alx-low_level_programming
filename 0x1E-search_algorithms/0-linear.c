#include "search_algos.h"
/**
 * linear_search - function that performs linear search algorithm
 * @array: pointer to the first elt of the array
 * @size: number of elts in the array
 * @value: is the searching value
 * Return: returns the first index where the value is located
 */
int linear_search(int *array, size_t size, int value)
{
	size_t counter = 0;

	if (!array || size == 0)
		return (-1);

	while (counter < size)
	{
		printf("Value checked array[%lu] = [%d]\n", counter, array[counter]);
		if (array[counter] == value)
			return (counter);
		counter++;
	}
	return (-1);
}
