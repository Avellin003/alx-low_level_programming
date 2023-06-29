#include "main.h"
/**
 * string_toupper - change lowercase to uppercase
 * @s:string
 * Return:char
 */
char *string_toupper(char *s)
{

	int a;

a = 0;
	while (*(s + a))
	{
		if (*(s + a) >= 'a' && *(s + a) <= 'z')
			*(s + a) -= 'a' - 'A';
		a++;
	}
	return (s);

