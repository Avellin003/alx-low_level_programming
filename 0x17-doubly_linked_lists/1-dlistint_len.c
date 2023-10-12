#include "lists.h"
/**
 * dlistint_len - prints out the number of elements
 * @h: pointer to list of ints
 * Return: number of elements in a linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int num = 0;

	if (h == NULL)
	{
		return (num);
	}
	while (h->prev != NULL)
	{
		h = h->prev;
	}
	while (h->next != NULL)
	{
		h = h->next;
		num++;
	}
	return (num + 1);
}
