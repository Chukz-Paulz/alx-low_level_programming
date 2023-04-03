#include "lists.h"

/**
 * print_listint_safe - Prints a linked list of integers
 *
 * @head: Pointer to the first node in the linked list
 *
 * Return: The number of nodes in the linked list
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *turtle, *hare;

    if (!head)
        exit(98);

    turtle = hare = head;
    while (turtle && hare && hare->next)
    {
        turtle = turtle->next;
        hare = hare->next->next;
        if (turtle == hare)
        {
            hare = head;
            while (turtle != hare)
            {
                count++;
                printf("[%p] %d\n", (void *)hare, hare->n);
                hare = hare->next;
                turtle = turtle->next;
            }
            printf("[%p] %d\n", (void *)hare, hare->n);
            return (count);
        }
    }

    while (head)
    {
        count++;
        printf("[%p] %d\n", (void *)head, head->n);
        head = head->next;
    }

    return (count);
}
