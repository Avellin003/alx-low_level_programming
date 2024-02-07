#include "search_algos.h"

/**
  * jump_search - function that uses jump algorithm to search a value
  * @array: input numbers to search through
  * @size: strlen of the input
  * @value: the value to search.
  *
  * Return: returns the the index of the value searching else -1
  */
int jump_search(int *array, size_t size, int value)
{
	size_t a, counter, jump;

	if (array == NULL || size == 0)
		return (-1);

	jump = sqrt(size);
	for (a = counter = 0; counter < size && array[counter] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", counter, array[counter]);
		a = counter;
		counter += jump;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", a, counter);

	counter = counter < size - 1 ? counter : size - 1;
	for (; a < counter && array[a] < value; a++)
		printf("Value checked array[%ld] = [%d]\n", a, array[a]);
	printf("Value checked array[%ld] = [%d]\n", a, array[a]);

	return (array[a] == value ? (int)a : -1);
}
