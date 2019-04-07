/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server_create
*/

#include <string.h>
#include "ftp/server.h"

server_t *server_create(char *ip_address, size_t port, size_t max_connections)
{
    server_t *server = NULL;

    if (ip_address == NULL)
        return (NULL);
    server = malloc(sizeof(server_t));
    if (server == NULL)
        return (NULL);
    server->ip_address = malloc((strlen(ip_address) + 1) * sizeof(char));
    if (server->ip_address == NULL)
        return (NULL);
    server->ip_address = strcpy(server->ip_address, ip_address);
    server->port = port;
    server->max_connections = max_connections;
    server->fd = -1;
    server->fd_max = -1;
    server->clients = NULL;
    server->commands = NULL;
    server->commands_conf = NULL;
    server->msg_queue = NULL;
    FD_ZERO(&server->master_fds);
    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->write_fds);
    return (server);
}