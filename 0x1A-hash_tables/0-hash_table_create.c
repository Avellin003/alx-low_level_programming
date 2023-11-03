#include "hash_tables.h"
/**
 * hash_table_create - function to create hash tables
 * @size: size array
 * Return: pointer to the new hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int a;
	hash_table_t *hash_table;

	hash_table = malloc(sizeof(hash_table_t));
	if (!hash_table)
		return (NULL);
	hash_table->size = size;
	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}
	for (a = 0; a < size; a++)
		hash_table->array[a] = NULL;
	return (hash_table);
}
