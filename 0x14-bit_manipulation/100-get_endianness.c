#include "main.h"
/**
 * get_endianness - function
 * Return: 0 for success or 1 for failure
 */
int get_endianness(void)
{
	int avellin;

	avellin = 1;
	if (*(char *)&avellin == 1)
		return (1);
	else
		return (0);
}
