#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * print_all - Prints all of the arguments when specified
 * @format: specifies the necessary operations
 * Return: void
 */

void print_all(const char * const format, ...)
{
	int a;
	int f;
	char *str;
	va_list a_list;

	va_start(a_list, format);
	a = 0;
	while (format != NULL && format[a] != '\0')
	{
		switch (format[a])
		{
			case 'c':
				printf("%c", va_arg(a_list, int));
				f = 0;
				break;
			case 'i':
				printf("%i", va_arg(a_list, int));
				f = 0;
				break;
			case 'f':
				printf("%f", va_arg(a_list, double));
				f = 0;
				break;
			case 's':
				str = va_arg(a_list, char*);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				f = 0;
				break;
			default:
				f = 1;
				break;
		}
		if (format[a + 1] != '\0' && f == 0)
			printf(", ");
		a++;
	}
	printf("\n");
	va_end(a_list);
}
