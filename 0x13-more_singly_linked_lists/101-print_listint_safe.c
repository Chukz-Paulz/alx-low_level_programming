#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a linked list
 * @head: A pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current = head;
    const listint_t *temp;
    size_t count = 0;

    while (current != NULL)
    {
        printf("[%p] %d\n", (void *) current, current->n);
        count++;
        temp = current;
        current = current->next;

        /* Check if current has been visited before */
        if (temp <= current)
        {
            printf("-> [%p] %d\n", (void *) current, current->n);
            exit(98);
        }
    }

    return (count);
}
