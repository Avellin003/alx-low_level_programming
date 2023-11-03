#include "hash_tables.h"
/**
 * hash_table_print - function that prints the hash table
 * @ht: pointer to the hash table
 * Return : return value is void
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *nd;
	unsigned long int a;
	unsigned char flag = 0;

	if (!ht)
		return;
	printf('{');
	for (a = 0; a < ht->size; a++)
	{
		if (!(ht->array[a]))
		{
			if (flag == 1)
				printf(", ");
			nd = ht->array[a];
			while (!nd)
			{
				printf("%s : %s", nd->key, nd->value);
				nd = nd->next;
				if (!nd)
					printf(", ");
			}
			flag = 1;
		}
	}
	printf("}\n");
}
