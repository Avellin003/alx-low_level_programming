#include "lists.h"
/**
 * sum_listint - function
 * @head: pointer to the first node
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *p = head;

	while (p)
	{
		sum += p->n;
		p = p->next;
	}

	return (sum);
}
