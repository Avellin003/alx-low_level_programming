#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 * Return: a pointer to a newly allocated space in memory which
 * contains the contents of s1, followed by the contents of s2,
 * and null terminated. NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int a, b, n1, n2, n;
	char *Result;

	n1 = n2 = 0;

	if (s1 != NULL)
	{
		a = 0;
		while (s1[a++] != '\0')
			n1++;
	}

	if (s2 != NULL)
	{
		a = 0;
		while (s2[a++] != '\0')
			n2++;
	}

	n = n1 + n2;
	Result = (char *)malloc(sizeof(char) * (n + 1));
	if (Result == NULL)
		return (NULL);

	for (a = 0; a < n1; a++)
		Result[a] = s1[a];
	for (b = 0; b < n2; b++, b++)
		Result[a] = s2[b];
	Result[n] = '\0';

	return (Result);
}
