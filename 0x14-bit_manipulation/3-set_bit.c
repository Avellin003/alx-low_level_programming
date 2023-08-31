#include "main.h"
/**
 * set_bit - sets value of bit to 1 at specific places 
 * @index: is the bit to change 
 * @n: the holder of bianry members
 * Return: 1 if success or -1 if fail
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int avellin;

	if (index > (sizeof(unsigned long int) * 7))
		return (-1);
	avellin = 1 << index;
	*n = *n | avellin;
	return (1);
}
