/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** queue_add_existing_queue
*/

#include "queue/queue.h"

bool queue_add_existing_queue(server_t *server, queue_t *queue)
{
    queue_t *head = NULL;

    if (server == NULL || queue == NULL)
        return (false);
    if (queue->element == NULL)
        return (false);
    queue->next = NULL;
    if (server->commands == NULL) {
        server->commands = queue;
        return (true);
    }
    queue->attempts++;
    queue->next = NULL;
    for (head = server->commands; head->next != NULL; head = head->next);
    head->next = queue;
    return (true);
}
