#include <stdlib.h>

/* Definition for singly-linked list */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

/* Function to reverse a linked list */
listint_t *reverse_listint(listint_t **head) {
    if (*head == NULL || (*head)->next == NULL)
        return *head;

    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}

