#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete a node at a specific position in list
 * @head: Pointer to the head of the list
 * @index: Position to delete the node
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	if (!head || !*head)
	return (-1);

	/*declaration*/
	dlistint_t *current = *head;

	if (index == 0)
	{
	*head = current->next;
	if (current->next)
		current->next->prev = NULL;
	free(current);
	return (1);
	}

	for (unsigned int counter = 0; counter < index && current; counter++)
	{
		if (current->next == NULL)
			return (-1);
		/*Declaration*/
		current = current->next;
	}

	if (current->prev)
		current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;

	free(current);

	return (1);
}
