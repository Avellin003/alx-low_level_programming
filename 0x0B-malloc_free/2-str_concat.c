#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: a pointer to a newly allocated space in memory which
 * contains the contents of s1, followed by the contents of s2,
 * and null terminated. NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, av1, av2, av;
	char *result;

	av1 = av2 = 0;

	if (s1 != NULL)
	{
		i = 0;
		while (s1[i++] != '\0')
			av1++;
	}

	if (s2 != NULL)
	{
		i = 0;
		while (s2[i++] != '\0')
			av2++;
	}

	av = av1 + av2;
	result = (char *)malloc(sizeof(char) * (av + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < av1; i++)
		result[i] = s1[i];
	for (j = 0; j < av2; j++, i++)
		result[i] = s2[j];
	result[av] = '\0';

	return (result);
}
