#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program.
 * @ac: arguments count
 * @av: arguments vector
 * Return: a pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *t, *s;
	int a, b, c, avy = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		s = av[a];
		b = 0;

		while (s[b++])
			avy++;
		avy++;
	}

	t = (char *)malloc(sizeof(char) * (avy + 1));
	if (t == NULL)
		return (NULL);

	for (a = 0, b = 0; a < ac && b < avy; a++)
	{
		s = av[a];
		c = 0;

		while (s[c])
		{
			t[b] = s[c];
			c++;
			b++;
		}
		t[b++] = '\n';
	}
	t[b] = '\0';

	return (t);
}
