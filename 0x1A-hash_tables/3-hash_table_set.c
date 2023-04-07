#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table to add or update the key/value to
 * @key: the key. key can not be an empty string
 * @value: the value associated with the key. value must be duplicated. value,
 * can be an empty string
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;

	/* check for valid input */
	if (ht == NULL || key == NULL || value == NULL || strlen(key) == 0)
		return (0);

	/* get the index of the key in the array */
	index = key_index((const unsigned char *)key, ht->size);

	/* check if the key already exists in the list */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			/* update the value and return */
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}

	/* create a new node and add it to the beginning of the list */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
