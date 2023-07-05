#include "main.h"
#include <stddef.h>
/**
 *_strchr - used to locate strings
 *@s: pointer to be return upon occerence of c
 *@c: loop terminator value
 *Return: the pointer c on occernce of c or Null for no value at all
 */
char *_strchr(char *s, char c)
{
	int a;

	while (1)
	{
		a = *s++;
		if (a == c)
		{
			return (s - 1);
		}
		if (a == 0)
		{
			return (NULL);
		}
	}
}
