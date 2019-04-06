/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** server_configure
*/

#include "ftp/server.h"

bool server_configure(server_t *server)
{
    if (server == NULL)
        return (false);
    hashmap_push(&server->commands_conf, "USER", &user_command_executor);
    hashmap_push(&server->commands_conf, "PASS", &pass_command_executor);
    printf("[Server] The configuration has been loaded\n");
    return (true);
}