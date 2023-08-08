#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * append_text_to_file - function that appends a text to the end
 * @filename: pointer argument
 * @text_content: pointer argument
 * Return: If success 1 else -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int x, y, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	x = open(filename, O_WRONLY | O_APPEND);
	y = write(x, text_content, length);

	if (x == -1 || y == -1)
		return (-1);

	close(x);

	return (1);
}
