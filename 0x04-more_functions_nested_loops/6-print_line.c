#include "main.h"

/**
 * print_line - prints straight line n times.
 * @n: times straight line is printed.
 * Return: no return.
 */
void print_line(int n)
{
	int x;

	for (x= 0;x < n; x++)
	{
		_putchar(95);
	}
	_putchar('\n');
}
