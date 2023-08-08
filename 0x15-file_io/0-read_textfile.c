#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * read_textfile - function that reads textfiles
 * @filename: A pointer argument
 * @letters: argument
 * Return: if success return text else 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t x, y, z;
	char *holder;

	if (filename == NULL)
		return (0);

	holder = malloc(sizeof(char) * letters);
	if (holder == NULL)
		return (0);

	x = open(filename, O_RDONLY);
	y = read(x, holder, letters);
	z = write(STDOUT_FILENO, holder, y);

	if (x == -1 || y == -1 || z == -1 || z != y)
	{
		free(holder);
		return (0);
	}

	free(holder);
	close(x);

	return (z);
}
