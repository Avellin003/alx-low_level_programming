#include "main.h"
/**
 *_print_rev_recursion - function that prints in inverse form
 *@s: pointer to unknown variable
 *return: void
 */
void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
