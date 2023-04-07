#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current, *tmp;

	/* check for valid input */
	if (ht == NULL)
		return;

	/* loop through the array of the hash table */
	for (i = 0; i < ht->size; i++)
	{
		/* free the list at each index */
		current = ht->array[i];
		while (current != NULL)
		{
			tmp = current->next; /* store the next node */
			free(current->key); /* free the key */
			free(current->value); /* free the value */
			free(current); /* free the node */
			current = tmp; /* move to the next node */
		}
	}

	/* free the array and the hash table structure */
	free(ht->array);
	free(ht);
}
