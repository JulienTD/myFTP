/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** queue_add_command
*/

#include "queue/queue.h"
// BUG
bool queue_push(queue_t **head, void *data)
{
    queue_t *queue = NULL;
    queue_t *curr = NULL;

    if (data == NULL)
        return (false);
    queue = malloc(sizeof(queue_t));
    if (queue == NULL)
        return (false);
    queue->data = data;
    queue->next = NULL;
    if (*head == NULL) { // BUG ICI *head a la place de head
        *head = queue;
        return (true);
    }
    for (curr = *head; curr->next != NULL; curr = curr->next);
    curr->next = queue;
    return (true);
}