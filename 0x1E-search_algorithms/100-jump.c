#include "search_algos.h"

/**
 * jump_search - searches for a value in an array of
 * integers using the Jump search algorithm
 * @arr: input array
 * @arr_size: size of the array
 * @target_value: value to search for
 * Return: index of the number
 */
int jump_search(int *arr, size_t arr_size, int target_value)
{
	int current_index, jump, step, previous_index;

	if (arr == NULL || arr_size == 0)
		return (-1);

	jump = (int)sqrt((double)arr_size);
	step = 0;
	previous_index = current_index = 0;

	do {
		printf("Value checked arr[%d] = [%d]\n", current_index, arr[current_index]);

		if (arr[current_index] == target_value)
			return (current_index);
		step++;
		previous_index = current_index;
		current_index = step * jump;
	} while (current_index < (int)arr_size && arr[current_index] < target_value);

	printf("Value found between indexes [%d] and [%d]\n",
			previous_index, current_index);

	for (; previous_index <= current_index &&
			previous_index < (int)arr_size; previous_index++)
	{
		printf("Value checked arr[%d] = [%d]\n",
				previous_index, arr[previous_index]);
		if (arr[previous_index] == target_value)
			return (previous_index);
	}

	return (-1);
}

