#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 *_strstr - locates a substring.
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int m, n;

	for (m = 0; haystack[m] != '\0'; m++)
	{
		for (n = 0; needle[n] != '\0'; n++)
		{
			if (haystack[m + n] != needle[n])
				break;
		}
		if (!needle[n])
			return (&haystack[m]);
	}
	return (NULL);
}
