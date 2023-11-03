#include "hash_tables.h"
/**
 * hash_table_print - fucntion that prints the table
 * @ht: pointer to the table
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t *temp;
	char flag = 0;

	if (!ht || ht->array == NULL)
		return;
	printf("{");
	for (a = 0; a < ht->size; a++)
	{
		temp = ht->array[a];
		while (!temp)
		{
			if (flag == 1)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			flag = 1;
			temp = temp->next;
		}
	}
	printf("}\n");
}
