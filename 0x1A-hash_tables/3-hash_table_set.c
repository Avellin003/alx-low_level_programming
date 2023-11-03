#include "hash_tables.h"
/**
 * create - function that makes new hash node
 * @key: key of the node
 * @value: the value of the node
 * Return: node, or null
 */
hash_node_t *create(const char *key, const char *value)
{
	hash_node_t *nd;

	nd = malloc(sizeof(hash_node_t));
	if (!nd)
		return (NULL);
	nd->key = strdup(key);
	if (nd->key == NULL)
	{
		free(nd);
		return (NULL);
	}
	nd->value = strdup(value);
	if (nd->value == NULL)
	{
		free(nd->key);
		free(nd);
		return (NULL);
	}
	return (nd);
}
/**
 * hash_table_set - sets the key value of the table
 * @ht: hash table to append stuffs
 * @key: data's key
 * @value: data for storage
 * Return: 1 if success else 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	hash_node_t *hash_node;
	hash_node_t *temp;
	char *new;

	if (!ht || ht->array == NULL || ht->size == 0 ||
			key == NULL || strlen(key) == 0 || !value)
		return (0);
	i = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[i];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new = strdup(value);
			if (!new)
				return (0);
			free(temp->value);
			temp->value = new;
			return (1);
		}
		temp = temp->next;
	}
	hash_node = create(key, value);
	if (!hash_node)
		return (0);
	hash_node->next = ht->array[i];
	ht->array[i] = hash_node;
	return (1);
}
