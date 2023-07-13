#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *malloc_checked - function checks malloc success
 *@b: an argument
 *Return: Pointer when success if not 98
 */
void *malloc_checked(unsigned int b)
{
	void *i;

	i = malloc(b);
	if (i == NULL)
		exit(98);
	return (i);

}
