#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Removes a node at a specific index from a list
 *
 * @head: A pointer to the first element of the list
 * @index: The index of the node to remove
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *start_ptr;
    dlistint_t *temp_ptr;
    unsigned int position;

    if (*head == NULL)
    {
        return (-1); // List is empty, deletion failed
    }
    start_ptr = *head;
    position = 0;
    while (position < index && *head != NULL)
    {
        *head = (*head)->next;
        position++;
    }
    if (position != index)
    {
        *head = start_ptr;
        return (-1); // Index out of range, deletion failed
    }
    if (index == 0)
    {
        temp_ptr = (*head)->next;
        free(*head);
        *head = temp_ptr;
        if (temp_ptr != NULL)
        {
            temp_ptr->prev = NULL;
        }
    }
    else
    {
        (*head)->prev->next = (*head)->next;
        free(*head);
        if ((*head)->next)
            (*head)->next->prev = (*head)->prev;
        *head = start_ptr;
    }
    return (1); // Deletion successful
}