#include "hash_tables.h"
/**
 * key_index - function that provides key's index
 * @key: key to find the index
 * @size: size of the table
 * Return: index of hte key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
