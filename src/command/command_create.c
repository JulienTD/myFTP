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
    printf("Command: |%s|\n", raw_cmd);
    // for (size_t i = 0; i < strlen(client->curr_command); i++)
    //     printf("Char: %c\n", client->curr_command[i]);
    if (client->curr_command) {
        free(client->curr_command);
        client->curr_command = NULL;
        client->command_length = 0;
        printf("[Server] The command has been reset\n");
    }
    return (command);
}