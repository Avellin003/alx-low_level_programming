#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
  * add_nodeint - inserts node
  * @head: double pointer
  * @n: argument
  * @other: counter
  * Return: void if success else return NULL
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *other;

	other = malloc(sizeof(listint_t));
	if (!other)
		return (NULL);

	other->n = n;
	other->next = *head;
	*head = oher;

	return (other);
}
