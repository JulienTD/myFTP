/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** server_execute_queue
*/

#include "ftp/server.h"

bool server_execute_queue_cmd(server_t *server)
{
    queue_t *queue = NULL;

    if (server == NULL)
        return (false);
    queue = queue_pop(&server->commands);
    while (queue) {
        command_dispatch(queue);
        queue = queue_pop(&server->commands);
    }
    return (true);
}
