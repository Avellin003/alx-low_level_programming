#include "search_algos.h"

/**
  * interpolation_search - function that uses interpolation to estimate
  * value's index
  * @array: the input numbers
  * @size: strlen of the array
  * @value: the value to search in question
  *
  * Return: if success the value's index else -1
  */
int interpolation_search(int *array, size_t size, int value)
{
	size_t a, m, s;

	if (array == NULL)
		return (-1);

	for (m = 0, s = size - 1; s >= m;)
	{
		a = m + (((double)(s - m) / (array[s] - array[m])) * (value - array[m]));
		if (a < size)
			printf("Value checked array[%ld] = [%d]\n", a, array[a]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", a);
			break;
		}

		if (array[a] == value)
			return (a);
		if (array[a] > value)
			s = a - 1;
		else
			m = a + 1;
	}

	return (-1);
}
