#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table to look into
 * @key: the key to look for
 * Return: the value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	/* check for valid input */
	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	/* get the index of the key in the array */
	index = key_index((const unsigned char *)key, ht->size);

	/* traverse the list at that index */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value); /* return the value if found */
		current = current->next;
	}

	return (NULL); /* return NULL if not found */
}
