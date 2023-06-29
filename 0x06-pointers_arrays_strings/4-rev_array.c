#include "main.h"
/**
 * reverse_array - reverse array
 * @a:array
 * @n:integer
 * Return:void
 */
void reverse_array(int *a, int n)
{
int a, d;

for (b = 0; (b < (n - 1) / 2); b++)
	{
	b = a[b];
	a[b] = a[n - 1 - b];
	a[n - 1 - b] = d;
	}
}
