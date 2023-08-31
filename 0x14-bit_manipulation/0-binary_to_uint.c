#include "main.h"
/**
 * binary_to_uint - converts binary to unsigned int
 * @b: pointer to the binary number members
 * Return: the number converted or else 0 if it failed
 */
unsigned int binary_to_uint(const char *b)
{
	int n;
	unsigned int num = 0;

	if (!b)
		return (0);
	for (n = 0; b[n] != '\0'; n++)
	{
		if (b[n] != '0' && b[n] != '1')
			return (0);
	}
	for (n = 0; b[n] != '\0'; n++)
	{
		num <<= 1;
		if (b[n] == '1')
			num += 1;
	}
	return (num);
}
