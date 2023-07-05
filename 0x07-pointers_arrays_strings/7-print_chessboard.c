#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * print_chessboard - prints the chessboard
 * @a: two dimension array to print
 * _putchar - function used to print
 */
void print_chessboard(char (*a)[8])
{
	int j, k;

	for (j = 0; j < 8; j++)
	{
		for (k = 0; k < 8; k++)
		{
			putchar(a[j][k]);
		}
		putchar('\n');
	}
}
