/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server_send
*/

#include "ftp/client.h"
#include "ftp/server.h"

bool server_send(server_t *server, client_t *client, char *msg)
{
    if (server == NULL || client == NULL || msg == NULL)
        return (false);
    if (!FD_ISSET(client->fd, &server->write_fds))
        return (false);
    write(client->fd, msg, strlen(msg));
    return (true);
}