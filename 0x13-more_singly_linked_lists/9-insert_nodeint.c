#include "lists.h"
/**
 * insert_nodeint_at_index - function
 * @head: pointer to node1
 * @idx: index where the new node will be added
 * @n: data
 * Return: pointer or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int a;
	listint_t *new;
	listint_t *p = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (a = 0; p && a < idx; a++)
	{
		if (a == idx - 1)
		{
			new->next = p->next;
			p->next = new;
			return (new);
		}
		else
			p = p->next;
	}

	return (NULL);
}
