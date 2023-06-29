#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: address of s
 */
char *leet(char *s)
{
	int m, n;
	char x[] = "aAeEoOtTlL";
	char y[] = "4433007711";

	for (m = 0; *(s + m); m++)
	{
		for (n = 0; n <= 9; n++)
		{
			if (x[m] == s[n])
				s[m] = y[n];
		}
	}
	return (s);

