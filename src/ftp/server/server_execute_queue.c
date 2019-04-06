/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** server_execute_queue
*/

#include "ftp/server.h"

bool server_execute_queue(server_t *server)
{
    queue_t *queue = NULL;

    if (server == NULL)
        return (false);
    queue = queue_retrieve_command(server);
    while (queue) {
        command_dispatch(queue);
        queue = queue_retrieve_command(server);
    }
    return (true);
}