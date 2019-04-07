/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** command_dispatch
*/

#include "command/command.h"
#include "queue/queue.h"

bool command_dispatch(queue_t *queue)
{
    command_t *command = NULL;
    bool (*func)(command_t *) = NULL;
    void *raw_data = NULL;

    if (queue == NULL)
        return (false);
    command = (command_t *)queue->data;
    raw_data = hashmap_get_value(&command->server->commands_conf, \
                                command->args[0]);
    if (raw_data == NULL) {
        printf("[Server] The socket %d sent an invalid command !\n", \
                command->client->fd);
        return (false);
    }
    func = raw_data;
    func(command);
    return (false);
}