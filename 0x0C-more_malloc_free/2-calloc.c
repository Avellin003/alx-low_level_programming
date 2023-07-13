#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 *_calloc - function allocates memory for an array
 *@nmemb: number elements
 *@size: variable
 *Return: pointer if success or NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *avellin;
	unsigned int b;

	if (nmemb == 0 || size == 0)
		return (NULL);
	avellin = malloc(nmemb * size);
	if (avellin == NULL)
		return (NULL);
	for (b = 0; b < (nmemb * size); b++)
		avellin[b] = 0;
	return (avellin);
}
