#include "main.h"
#include <stdio.h>
/**
 *print_binary - binary converter
 *@n: input
 *Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int num;
	int counter;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (num = n, counter = 0; (num >>= 1) > 0; counter++)
		;

	for (; counter >= 0; counter--)
	{
		if ((n >> counter) & 1)
			printf("1");
		else
			printf("0");
	}
}
