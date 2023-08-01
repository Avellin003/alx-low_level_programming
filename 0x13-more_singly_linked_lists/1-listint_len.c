#include "lists.h"
#include <string.h>
#include <stdio.h>
/**
 * listint_len - prints num
 * @h: pointer used access data in listint_t
 * Return: size_t
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h != NULL)
	{
		h = h->next;
		num++;
	}
	return (num);
}
