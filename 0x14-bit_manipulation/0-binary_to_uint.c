#include "main.h"
#include <stdio.h>
/**
 * binary_to_uint - converts 0b unsigned int
 * @b: pointer to string of binary characters
 * Return: converted int if success full or 0 if not
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int digit;

	digit = 0;
	if (!b)
		return (0);
	for (a = 0; b[a] != '\0'; a++)
	{
		if (b[a] != '0' && b[a] != '1')
			return (0);
	}
	for (a = 0; b[a] != '\0'; a++)
	{
		digit <<= 1;
		if (b[a] == '1')
			digit += 1;
	}
	return (digit);
}
