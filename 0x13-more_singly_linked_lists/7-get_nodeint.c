#include "lists.h"
/**
 * get_nodeint_at_index - function
 * @head: first node pointer
 * @index: integer
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int a = 0;
	listint_t *p = head;

	while (p && a < index)
	{
		p = p->next;
		a++;
	}

	return (p ? p : NULL);
}
