#include "main.h"

/**
 * print_diagonal - prints diagonal line n times.
 * @n: times diagonal line is printed.
 * Return: no return.
 */
void print_diagonal(int n)
{
	int x, z;

	for (x = 0; x < n; x++)
	{
		for (z = 0; z < x; z++)
		{
			_putchar(' ');
		}
		_putchar(92);
		if (x < (n - 1))
			_putchar('\n');
	}
	_putchar('\n');
}
