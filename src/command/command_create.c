/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** command_create
*/

#include "command/command.h"

command_t *command_create(server_t *server, client_t *client, char *raw_cmd)
{
    command_t *command = NULL;

    if (server == NULL || client == NULL)
        return (NULL);
    command = malloc(sizeof(command_t));
    if (command == NULL)
        return (NULL);
    command->server = server;
    command->client = client;
    command->args = NULL;
    command->args_length = 0;
    // TODO: remove \r\n and if there is char after it, we must keep it to reinject it to the system
    printf("Command: |%s|\n", raw_cmd);
    if (client->curr_command) {
        free(client->curr_command);
        client->curr_command = NULL;
        client->command_length = 0;
        printf("[Server] The command has been reset\n");
    }
    return (command);
}