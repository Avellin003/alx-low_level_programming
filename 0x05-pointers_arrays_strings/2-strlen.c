#include "main.h"

/**
 *_strlen - prints the length  of char
 *@s: char holding data
 *Return: String length
 */
int _strlen(char *s)
{
	int bonaparte = 0;

	for (; *s != '\0'; s++)
	{
		bonaparte++;
	}

	return (bonaparte);
}
