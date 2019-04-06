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
    char **commands = NULL;

    if (server == NULL || client == NULL)
        return (NULL);
    command = command_init(server, client);
    if (command == NULL)
        return (NULL);
    commands = my_str_split(raw_cmd, "\r\n");
    if (commands == NULL)
        return (NULL);
    command->args = my_str_split(commands[0], " ");
    for (int i = 0; command->args && command->args[i]; i++, command->args_length++);
    if (client->curr_command) {
        free(client->curr_command);
        client->curr_command = NULL;
        client->command_length = 0;
        printf("[Server] The command has been reset\n");
    }
    return (command);
}