#include "lists.h"
/**
 * add_dnodeint_end - function that adds node at the beginning
 * @head: pointer to the first node
 * @n: data at nodes
 * Return: new element's address
 * if success else NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_h;
	dlistint_t *nh;

	new_h = malloc(sizeof(dlistint_t));
	if (new_h == NULL)
		return (NULL);

	new_h->n = n;
	new_h->next = NULL;
	nh = *head;
	if (nh != NULL)
	{
		while (nh->next != NULL)
		{
			nh = nh->next;
		}
	}
	new_h->prev = nh;
	if (nh != NULL)
		nh->next = new_h;
	*head = new_h;
	return (new_h);
}
