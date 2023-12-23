#include "hash_tables.h"

/**
 * hash_table_set - This adds or updates an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *new_node = malloc(sizeof(hash_node_t));
	hash_node_t *current = ht->array[index];

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	/* Check if key already exists in the linked list at the calculated index */
	/*hash_node_t *current = ht->array[index];*/
	while (current)
	{
	if (strcmp(current->key, key) == 0)
		{
		/* Key found, update the value and free the duplicate value */
		free(current->value);
		current->value = strdup(value);
		if (current->value == NULL)
			return (0);
		return (1);
		}
		current = current->next;
	}

	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	/* Insert the new node at the beginning of the linked list */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
