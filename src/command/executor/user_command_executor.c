/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** user_command_executor
*/

#include "command/command.h"

bool user_command_executor(command_t *command)
{
    char **args = NULL;
    server_t *server = NULL;
    client_t *client = NULL;

    if (command == NULL || command->args_length <= 1)
        return (false);
    server = command->server;
    client = command->client;
    args = command->args;
    if (strcmp(args[1], "Anonymous") == 0) {
        server_send(server, client, "331 User name okay, need password.\r\n");
        printf("[Server] The socket %d is trying to connect as %s\n", client->fd, "Anonymous");
        client->username = calloc(10, sizeof(char));
        client->username = strcpy(client->username, "Anonymous");
        return (true);
    }
    return (true);
}