#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * add_node - Adds a new node at the end of a list_t list.
 * @head: A pointer to the head of the list.
 * @str: The string to be duplicated and added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
    if (str == NULL)
        return NULL;

    list_t *new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return NULL;

    char *str_copy = strdup(str);
    if (str_copy == NULL) {
        free(new_node);
        return NULL;
    }

    new_node->str = str_copy;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        list_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    return new_node;
}

