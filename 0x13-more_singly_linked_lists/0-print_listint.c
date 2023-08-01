#include "lists.h"
#include <string.h>
#include <stdio.h>

/**
 * print_listint - prints elements
 * @h: pointer used access data in listint_t
 * Return: size_t
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;
	
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		num++;
	}
	return (num);
}
