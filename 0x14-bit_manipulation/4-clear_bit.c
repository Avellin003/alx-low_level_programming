#include "main.h"
/**
 * clear_bit - sets bit's value to zero
 * @n: pointer to the inputs
 * @index: the tracker
 * Return: 1 success or -1 if failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int avellin;

	if (index > (sizeof(unsigned long int) * 7))
		return (-1);
	avellin = ~(1 << index);
	*n = *n & avellin;

	return (1);
}
