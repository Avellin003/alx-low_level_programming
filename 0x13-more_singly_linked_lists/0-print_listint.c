#include "lists.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
/**
 * print_listint - prints elements
 * @num: number of nodes
 * @h: pointer used access data in listint_t
 * Return: num
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
