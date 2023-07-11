#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the source string
 * Return: returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *apollon;
	int i, n = 0;

	if (str == NULL)
		return (NULL);

	while (str[n] != '\0')
		n++;

	apollon = (char *)malloc((sizeof(char) * n) + 1);
	if (apollon == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		apollon[i] = str[i];
	apollon[n] = '\0';

	return (apollon);
}
