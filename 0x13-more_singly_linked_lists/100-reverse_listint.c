#include <stddef.h>
#include "lists.h"

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL, *next = NULL;

    while (*head != NULL)
    {
        next = (*head)->next; // Store the next node
        (*head)->next = prev; // Reverse the link

        prev = *head; // Move prev to current node
        *head = next; // Move head to next node
    }

    *head = prev; // Update head to the new first node (which was the last node)

    return *head;
}

