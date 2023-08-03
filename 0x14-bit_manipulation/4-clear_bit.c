#include "main.h"
/**
 * clear_bit - function
 * @n: pointer argument
 * @index: argument
 * Return: 1 success or -1 if failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int a;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	a = ~(1 << index);
	*n = *n & a;

	return (1);
}
