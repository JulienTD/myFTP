/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** queue_pop
*/

#include "queue/queue.h"

queue_t *queue_pop(queue_t **head)
{
    queue_t *queue = NULL;

    if (head == NULL || *head == NULL)
        return (NULL);
    queue = *head;
    *head = queue->next;
    return (queue);
}