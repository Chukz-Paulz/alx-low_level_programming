#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with
 *                  a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
        hash_node_t *current = ht->array[index];
	
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	if (index >= ht->size)
		return (NULL);

	/* Traverse the linked list at the calculated index to find the key */
	/*hash_node_t *current = ht->array[index];*/
	while (current && strcmp(current->key, key) != 0)
		current = current->next;

	/* Return the value if key is found, otherwise return NULL */
	return (current == NULL ? NULL : current->value);
}
