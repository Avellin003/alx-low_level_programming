#include "main.h"
/**
 * get_endianness - function
 * Return: 0 for success or 1 for failure
 */
int get_endianness(void)
{
	int a;

	a = 1;
	if (*(char *)&a == 1)
		return (1);
	else
		return (0);
}
