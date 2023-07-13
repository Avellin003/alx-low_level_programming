#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 *string_nconcat - concatates two strings
 *@s1: string a
 *@s2: string b
 *@n: variable
 *Return: pointer to the new string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int a, b, c;
	char *avellin;

	if (s1 == NULL)
	{
		a = 0;
	}
	else
	{
		for (a = 0; s1[a]; ++a)
		;
	}
	if (s2 == NULL)
	{
		b = 0;
	}
	else
	{
		for (b = 0; s2[b]; ++b)
		;
	}
	if (b > n)
		b = n;
	avellin = malloc(sizeof(char) * (a + b + 1));
	if (avellin == NULL)
		return (NULL);
	for (c = 0; c < a; c++)
		avellin[c] = s1[c];
	for (c = 0; c < b; c++)
		avellin[c + a] = s2[c];
	avellin[a + b] = '\0';
	return (avellin);
}
