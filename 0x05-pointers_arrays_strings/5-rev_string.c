#include "main.h"
#include <stdio.h>
/**
  * rev_string - Reverses a string
  * @s: The string to be modified
  *
  * Return: void
  */
void rev_string(char *s)
{
	int k, l; 
	char ss;

	for (k = 0; s[k] != '\0'; ++k)
		;
	for (l = 0; l < k / 2; ++l)
	{
		ss = s[l];
		s[l] = s[k - 1 - l];
		s[k - 1 - l] = ss;
	}

}
