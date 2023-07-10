#include <stdio.h>
/**
 * main - prints the number of arguments
 * @Argc: argument for count
 * @Argv: argument vector
 * Return: 0
 */
int main(int Argc, char **Argv)
{
	(void)Argv;
	printf("%d \n", Argc - 1);
	return (0);
}
