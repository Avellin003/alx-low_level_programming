#include "main.h"
#include <stdio.h>
/**
 * create_file - fx that creates a file
 * @filename: pointer argument
 * @text_content: pinter argument
 * Return: If success 1 else -1
 */
int create_file(const char *filename, char *text_content)
{
	int y, z, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	y = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	z = write(y, text_content, length);

	if (y == -1 || z == -1)
		return (-1);

	close(y);

	return (1);
}
