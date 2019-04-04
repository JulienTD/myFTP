/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** queue_retrieve_command
*/

#include "queue/queue.h"

queue_t *queue_retrieve_command(server_t *server)
{
    queue_t *queue = NULL;

    if (server == NULL || server->commands == NULL)
        return (NULL);
    queue = server->commands;
    server->commands = queue->next;
    return (queue);
}