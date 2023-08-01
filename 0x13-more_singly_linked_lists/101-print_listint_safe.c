#include "lists.h"
/**
 * print_listint_safe - function
 * @head: pointer
 * Return: new_node
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *p_n = NULL;
	const listint_t *l_n = NULL;
	size_t num = 0;
	size_t new_n;

	p_n = head;
	while (p_n)
	{
		printf("[%p] %d\n", (void *)p_n, p_n->n);
		num++;
		p_n = p_n->next;
		l_n = head;
		new_n = 0;
		while (new_n < num)
		{
			if (p_n == l_n)
			{
				printf("-> [%p] %d\n", (void *)p_n, p_n->n);
				return (num);
			}
			l_n = l_n->next;
			new_n++;
		}
		if (!head)
			exit(98);
	}
	return (num);
}
