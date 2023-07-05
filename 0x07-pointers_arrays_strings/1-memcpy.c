#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * _memcpy - a function used to copy n bytes to a memory area
 * @n: times to copy
 * @src: variable to copy from
 * @dest: variable to copy to
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		src[i] = dest[i];
	return (dest);
}
