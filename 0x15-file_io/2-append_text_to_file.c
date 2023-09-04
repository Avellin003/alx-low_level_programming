#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * append_text_to_file - adds text to the end of another
 * @filename: pointer argument
 * @text_content: pointer argument
 * Return: If success 1 else -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int y, z, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	y = open(filename, O_WRONLY | O_APPEND);
	z = write(y, text_content, length);

	if (y == -1 || z == -1)
		return (-1);

	close(y);

	return (1);
}
