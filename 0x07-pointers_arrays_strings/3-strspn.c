#include "main.h"

/**
 *_strspn - gets the length of a prefix substring
 * @s: string to evaluate
 * @accept: string containing the list of characters to match in s
 *
 * Return: the number of bytes in the initial segment
 * of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int k, j, f, flag;

	f = 0;

	for (k = 0; s[k] != '\0'; k++)
	{
		flag = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[k] == accept[j])
			{
				f++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return (f);
		}
	}

	return (0);
}
