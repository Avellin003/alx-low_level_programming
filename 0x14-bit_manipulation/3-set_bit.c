#include "main.h"
/**
 * set_bit - function
 * @index: Argument
 * @n: Argument
 * Return: 1 if success or -1 if fail
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int a;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	a = 1 << index;
	*n = *n | a;
	return (1);
}
