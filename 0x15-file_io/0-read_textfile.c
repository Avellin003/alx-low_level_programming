#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * read_textfile - function that reads
 * @filename: A pointer argument
 * @letters: argument
 * Return: if success return text else 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t y, z, a;
	char *hold;

	if (filename == NULL)
		return (0);

	hold = malloc(sizeof(char) * letters);
	if (hold == NULL)
		return (0);

	y = open(filename, O_RDONLY);
	z = read(y, hold, letters);
	a = write(STDOUT_FILENO, hold, z);

	if (y == -1 || z == -1 || a == -1 || a != z)
	{
		free(hold);
		return (0);
	}

	free(hold);
	close(y);

	return (a);
}
