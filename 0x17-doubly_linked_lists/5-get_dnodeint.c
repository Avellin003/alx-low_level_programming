#include "lists.h"
/**
 * get_dnodeint_at_index - tracks a given node
 * @head: pointer to the first node
 * @index: the nth number of node to get
 * Return: pointer to node if success else NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int a;

	if (head == NULL)
		return (NULL);
	if (index == 0)
		return (head);
	for (a = 0; a < index; a++)
	{
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
