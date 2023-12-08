#include "lists.h"

/**
 * add_dnodeint - Inserts a new node at the beginning of a doubly linked list
 * @head: Pointer to the head of the list
 * @n: The data integer for the new node
 * Return: Pointer to the new node, or NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	if (!head)
		return (NULL);

	/*Declaration*/
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;

	/*returns New nide*/
	return (new_node);
}
