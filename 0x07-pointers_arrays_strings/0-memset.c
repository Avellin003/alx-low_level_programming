#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * _memset - sets the first count bytes of dest to the value c
 * @s: a pointer to n
 * @n: number of times to copy b
 * @b: value to be filled in the first bytes of n
 * retun: pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n ; i++)
	s[i] = b;

	return (s);
}
