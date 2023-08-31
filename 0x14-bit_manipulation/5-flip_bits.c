#include <stdio.h>
/**
 * flip_bits - provides the number that is needed
 * to move to next n
 * @n: tracker 1
 * @m: tracker 2
 * Return: bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int y;
	int z;

	y = n ^ m;
	z = 0;

	while (y)
	{
		z++;
		y &= (y - 1);
	}

	return (z);
}
