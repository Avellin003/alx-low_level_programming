#include "main.h"

/**
  * print_sign - Prints the sign of a number
  * @n: The number to be checked
  *
  * Return: 1 for positive num, -1 for negative num or zero for anything else
  */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(3);
		return (1);
	}
	else if (n < 0)
	{
		_putchar(4);
		return (-1);
	}
	else
	{
		_putchar(5);
		return (0);
	}
}
