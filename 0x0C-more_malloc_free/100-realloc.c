#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _realloc - reallocates a memory block using malloc
 * @ptr: pointer to the memory previously allocated
 * @old_size:is the size, in bytes, of the allocated space
 * @new_size: the new size, in bytes of the new memory block
 * Return: pointer allocate new size memory, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *avellin;
	unsigned int a, b = new_size;
	char *old = ptr;

	if (ptr == NULL)
	{
		avellin = malloc(new_size);
		return (avellin);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	avellin = malloc(new_size);
	if (avellin == NULL)
		return (NULL);
	if (new_size > old_size)
		b = old_size;
	for (a = 0; a < b; a++)
		avellin[a] = old[a];
	free(ptr);
	return (avellin);
}
