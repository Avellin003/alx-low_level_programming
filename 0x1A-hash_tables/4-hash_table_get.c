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

	if (!ht || !key || *key == '\0')
		return (NULL);
	i = key_index((const unsigned char *)key, ht->size);
	if (i >= ht->size)
		return (NULL);
	temp = ht->array[i];
	while (temp && strcmp(temp->key, key) != 0)
	{
		temp = temp->next;
	}
	return ((temp == NULL) ? NULL : temp->value);
}
