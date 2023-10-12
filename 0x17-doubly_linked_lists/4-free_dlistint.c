#include "lists.h"
/**
 * free_dlistint - function that frees list
 * @head: pointer to pointer of the nodes
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *f;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;
	}
	while ((f = head) != NULL)
	{
		head = head->next;
		free(f);
	}
}
