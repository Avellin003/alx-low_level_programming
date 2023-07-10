#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the min number of coins to make change
 * for an amount of money
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	int T, C;
	unsigned int x;
	char *p;
	int cents[] = {25, 10, 5, 2};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	T = strtol(argv[1], &p, 10);
	C = 0;

	if (!*p)
	{
		while (T > 1)
		{
			for (x = 0; x < sizeof(cents[x]); x++)
			{
				if (cents[x] >= T)
				{
					C += T / cents[x];
					T = T % cents[x];
				}
			}
		}
		if (T == 1)
			C++;
	}
	else
	{
		printf("Error\n");
		return (1);
	}

	printf("%d\n", C);
	return (0);
}
