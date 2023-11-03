#include "hash_tables.h"
/**
 * hash_table_get - function that gets value of the key
 * @ht: table to get the value from
 * @key: key of the value
 * Return: value of the key or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i;
	hash_node_t *temp;

	if (!ht || ht->array == NULL || ht->size == 0 ||
			!key || strlen(key) == 0)
		return (NULL);
	i = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[i];
	while (!temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
