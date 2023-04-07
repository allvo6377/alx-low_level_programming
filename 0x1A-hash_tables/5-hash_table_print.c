#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;
	int flag = 0;

	/* check for valid input */
	if (ht == NULL)
		return;

	/* print the opening curly brace */
	printf("{");

	/* loop through the array of the hash table */
	for (i = 0; i < ht->size; i++)
	{
		/* traverse the list at each index */
		current = ht->array[i];
		while (current != NULL)
		{
			/* print a comma and a space if not the first element */
			if (flag == 1)
				printf(", ");

			/* print the key and the value */
			printf("'%s': '%s'", current->key, current->value);

			/* set the flag to indicate that an element has been printed */
			flag = 1;

			/* move to the next node */
			current = current->next;
		}
	}

	/* print the closing curly brace and a newline */
	printf("}\n");
}
