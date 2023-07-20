#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * sum_them_all - adds all the numbers
 * @n: the number of parameters passed
 * Return: Always 0
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int b;
	va_list a;

	va_start(a, n);

	if (n == 0)
	{
		return (0);
	}

	for (b = 0; b < n; b++)
		sum += va_arg(a, int);

	va_end(a);

	return (sum);
}
