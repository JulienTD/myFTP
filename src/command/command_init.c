/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** command_init
*/

#include "command/command.h"

command_t *command_init(server_t *server, client_t *client)
{
    command_t *command = NULL;

    if (server == NULL || client == NULL)
        return (NULL);
    command = malloc(sizeof(command_t));
    if (command == NULL)
        return (NULL);
    command->client = client;
    command->server = server;
    command->args = NULL;
    command->args_length = 0;
    return (command);
}