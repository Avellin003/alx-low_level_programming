#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_strings - prints strings
 * @separator: separator between strings
 * @n: number of arguments
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int a;
	char *m;

	va_list list;

	va_start(list, n);

	for (a = 0; a < n; a++)
	{
		m = va_arg(list, char *);
		if (!m)
			m = "(nil)";
		if (!separator)
			printf("%s", m);
		else if (separator && a == 0)
			printf("%s", m);
		else
			printf("%s%s", separator, m);
	}

	printf("\n");

	va_end(list);
}
