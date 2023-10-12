#include "lists.h"
/**
 * add_dnodeint - function that adds node at the beginning
 * @head: pointer to the first node
 * @n: data at nodes
 * Return: new element's address
 * if success else NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_h;
	dlistint_t *nh;

	new_h = malloc(sizeof(dlistint_t));
	if (new_h == NULL)
		return (NULL);

	new_h->n = n;
	new_h->prev = NULL;
	nh = *head;
	if (nh != NULL)
	{
		while (nh->prev != NULL)
		{
			nh = nh->prev;
		}
	}
	new_h->next = nh;
	if (nh != NULL)
		nh->prev = new_h;
	*head = new_h;
	return (new_h);
}
