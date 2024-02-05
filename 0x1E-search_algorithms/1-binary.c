#include "search_algos.h"

/**
 * binary_search - function that performs binary search algorithm
 * @array: pointer to the first elt of the array
 * @size: number of elts in the array
 * @value: is the searching value
 * Return: returns the index where the value is located or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid;
	size_t i;

	if (!array || size == 0)
		return (-1);

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
