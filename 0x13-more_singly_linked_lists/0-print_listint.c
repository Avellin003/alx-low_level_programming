#include "lists.h"
/**
 * print_listint - prints elements
 * @h: pointer used access data in listint_t
 * Return: the counter x
 */
size_t print_listint(const listint_t *h)
{
	size_t x = 0;

	while (h)
	{
		printf("%d\n", h->n);
		x++;
		h = h->next;
	}
	return (x);
}
