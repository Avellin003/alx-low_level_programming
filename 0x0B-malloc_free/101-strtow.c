#include "main.h"
#include <stdlib.h>

void util(char **, char *);
void create_word(char **, char *, int, int, int);

/**
 * strtow - splits a string into words.
 * @str: the string
 * Return: returns a pointer to an array of strings
 */
char **strtow(char *str)
{
	int i, g, avy;
	char **words;

	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);

	i = g = avy = 0;
	while (str[i])
	{
		if (g == 0 && str[i] != ' ')
			g = 1;
		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			g = 0;
			avy++;
		}
		i++;
	}

	avy += g == 1 ? 1 : 0;
	if (avy == 0)
		return (NULL);

	words = (char **)malloc(sizeof(char *) * (avy + 1));
	if (words == NULL)
		return (NULL);

	util(words, str);
	words[avy] = NULL;
	return (words);
}

/**
 * util - a util function for fetching words into an array
 * @words: the strings array
 * @str: the string
 */
void util(char **words, char *str)
{
	int i, j, start, g;

	i = j = g = 0;
	while (str[i])
	{
		if (g == 0 && str[i] != ' ')
		{
			start = i;
			g = 1;
		}

		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			create_word(words, str, start, i, j);
			j++;
			g = 0;
		}

		i++;
	}

	if (g == 1)
		create_word(words, str, start, i, j);
}

/**
 * create_word - creates a word and insert it into the array
 * @words: the array of strings
 * @str: the string
 * @start: the starting index of the word
 * @end: the stopping index of the word
 * @index: the index of the array to insert the word
 */
void create_word(char **words, char *str, int start, int end, int index)
{
	int i, j;

	i = end - start;
	words[index] = (char *)malloc(sizeof(char) * (i + 1));

	for (j = 0; start < end; start++, j++)
		words[index][j] = str[start];
	words[index][j] = '\0';
}
