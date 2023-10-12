#include "lists.h"
/**
 * sum_dlistint - function that performs sum of all data
 * @head: pointer to first pointer
 * Return: sum of all data
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;

	while (head != NULL)
	{
		total = total + head->n;
		head = head->next;
	}
	return (total);
}
