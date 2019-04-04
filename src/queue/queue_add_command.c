/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** queue_add_command
*/

#include "queue/queue.h"

bool queue_add_command(server_t *server, command_t *command)
{
    queue_t *queue = NULL;
    queue_t *head = NULL;

    if (server == NULL || command == NULL)
        return (false);
    queue = malloc(sizeof(queue_t));
    if (queue == NULL)
        return (false);
    queue->element = bs_list_create(command);
    if (server->commands == NULL) {
        server->commands = queue;
        return (true);
    }
    queue->attempts = 1;
    queue->next = NULL;
    for (head = server->commands; head->next != NULL; head = head->next);
    head->next = queue;
    return (true);
}