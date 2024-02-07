#include "search_algos.h"

/**
 * jump_search - function that performs jump search algorithm
 * @array: pointer to the first elt of the array
 * @size: number of elts in the array
 * @value: is the searching value
 * Return: returns the index where the value is located or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt((size - 1));
	size_t counter = 0;

	if (!array || size == 0)
		return (-1);
	while(counter < size)
	{
		if (array[counter] == value)
		{
			return (counter);
		}
		else if (array[counter] < value)
		{
			printf("Value checked array[%ld] = [%d]\n", counter, array[counter]);
			counter += jump;
		}
		else if (array[counter] > value)
		{
			printf("Value checked array[%ld] = [%d]\n", counter, array[counter]);
			counter -= 1;
		}
		else
			return (-1);
	}
	return (-1);
}
