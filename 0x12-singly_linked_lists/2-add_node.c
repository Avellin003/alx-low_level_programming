#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * _strlen - prints out the length of a string
 * @s : s is a character
 * Return: number of string
 */
int _strlen(const char *s)
{
	int a = 0;

	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

/**
 * add_node - adds a new node
 * @head: head of list
 * @str: value to inserts
 * Return: the number of nodes
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *add;

	add = malloc(sizeof(list_t));
	if (add == NULL)
		return (NULL);
	add->str = strdup(str);

	add->len = _strlen(str);
	add->next = *head;
	*head = add;

	return (add);
}
