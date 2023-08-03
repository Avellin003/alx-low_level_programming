#include <stdio.h>
/**
 * flip_bits - function
 * @n: argument 1
 * @m: argument 2
 * Return: bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x;
	int y;

	x = n ^ m;
	y = 0;

	while (x)
	{
		y++;
		x &= (x - 1);
	}

	return (y);
}
