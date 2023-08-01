#include "lists.h"
/**
 * free_listint_safe - function
 * @h: pointer to the first node
 * Return: number of elements
 */
size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	int d;
	listint_t *p;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		d = *h - (*h)->next;
		if (d > 0)
		{
			p = (*h)->next;
			free(*h);
			*h = p;
			length++;
		}
		else
		{
			free(*h);
			*h = NULL;
			length++;
			break;
		}
	}

	*h = NULL;

	return (length);
}
