/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** pass_command_executor
*/

#include "command/command.h"

bool pass_command_executor(command_t *command)
{
    char **args = NULL;
    server_t *server = NULL;
    client_t *client = NULL;

    if (command == NULL)
        return (false);
    server = command->server;
    client = command->client;
    args = command->args;
    if (client->username == NULL)
        return (false);
    if (strcmp(client->username, "Anonymous") == 0) {
        if (command->args_length != 1)
            return (false);
        server_send(server, client, "230 User logged in, proceed. Logged out if appropriate.\r\n");
        printf("[Server] The socket %d is now connected as %s\n", client->fd, "Anonymous");
        client->is_logged = true;
        return (true);
    }
    return (true);
}