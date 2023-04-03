#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
    const listint_t *tortoise, *hare;
    size_t nodes = 1;

    if (head == NULL || head->next == NULL)
        return (0);

    tortoise = head->next;
    hare = (head->next)->next;

    while (hare)
    {
        if (tortoise == hare)
        {
            tortoise = head;

            while (tortoise != hare)
            {
                nodes++;
                tortoise = tortoise->next;
                hare = hare->next;
            }

            tortoise = tortoise->next;

            while (tortoise != hare)
            {
                nodes++;
                tortoise = tortoise->next;
            }

            return (nodes);
        }

        tortoise = tortoise->next;
        hare = (hare->next)->next;
    }

    return (0);
}

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to the head of the listint_t list.
 *
 * Return: The size of the list that was free'd.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t nodes, index = 0;
    listint_t *current, *tmp;

    nodes = looped_listint_len(*h);

    if (nodes == 0)
    {
        while (*h != NULL)
        {
            current = (*h);
            *h = (*h)->next;
            free(current);
            index++;
        }
    }
    else
    {
        for (index = 0; index < nodes; index++)
        {
            printf("[%p] %d\n", (void *)*h, (*h)->n);
            current = (*h);
            *h = (*h)->next;
            free(current);
        }
        printf("-> [%p] %d\n", (void *)*h, (*h)->n);
        *h = NULL;
        nodes++;
    }

	return (nodes);
}
