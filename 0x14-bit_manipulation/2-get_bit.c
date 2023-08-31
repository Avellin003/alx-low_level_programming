#include "main.h"
#include <stdio.h>
/**
 * get_bit - gives the binary member of specific place
 * @n: input
 * @index: checks out if it exceeds the 64 bits value
 * Return: binary member else -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int avellin;

	if (index > 64)
		return (-1);

	avellin = n >> index;

	return (avellin & 1);
}
