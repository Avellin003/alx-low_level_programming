#include "main.h"
#include <stdio.h>
/**
 * get_bit - gives in  bit the value of an index
 * @n: num to process
 * @index: argument
 * Return: bit or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int k;

	if (index > 64)
		return (-1);

	k = n >> index;

	return (k & 1);
}
