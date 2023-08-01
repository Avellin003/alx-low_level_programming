#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
  * add_nodeint - inserts node
  * @head: double pointer
  * @n: argument
  * @x: counter
  * Return: void if success else return NULL
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *x;

	if (head == NULL)
		return (NULL);
	x = malloc(sizeof(listint_t));
	if (x == NULL)
		return (NULL);
	x->n = n;
	x->next = *head;
	*head = x;
	return (x);
}
