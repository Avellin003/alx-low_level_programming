#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * _strlen - gives length of a string
 * @str: string
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int a;

	for (a = 0; str[a]; a++);
	return (a);
}

/**
 * add_node_end - adds a new node
 * @head: pointer to the first node
 * @str: string
 * Return: pointer to the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *tmp;

	if (str == NULL)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->len = _strlen(new->str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}
