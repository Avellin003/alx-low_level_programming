#include "lists.h"
/**
 * pop_listint - function
 * @head: pointer
 * Return: data deleted or 0 if none
 */
int pop_listint(listint_t **head)
{
	listint_t *p;
	int i;

	if (!head || !*head)
		return (0);

	i = (*head)->n;
	p = (*head)->next;
	free(*head);
	*head = p;

	return (i);
}
