#include "main.h"
/**
 * print_alphabet - print_alphabetsx10
 */
void print_alphabet_x10(void)
{
	char letters;
	
	int i=0;
 	
	
	while (i<10)
	{
		for (letters = 'a'; letters <= 'j'; letters++)
		{
			_putchar(letters);
		}
		_putchar('\n');

		i++;
	}
}
