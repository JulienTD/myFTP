/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server_broadcast
*/

#include "ftp/server.h"
#include "ftp/client.h"

static bool send_data(bs_list_t *element, va_list *args)
{
    server_t *server = (server_t *)va_arg(*args, void *);
    client_t *base_client = (client_t *)va_arg(*args, void *);
    char *msg = (char *)va_arg(*args, void *);
    client_t *client = (client_t *)element->data;

    if (!FD_ISSET(client->fd, &server->write_fds))
        return (false);
    if (base_client == NULL || client->fd != base_client->fd)
            write(client->fd, msg, strlen(msg));
    return (true);
}

bool server_broadcast(server_t *server, client_t *client, char *msg)
{
    if (server == NULL || msg == NULL)
        return (false);
    bs_list_each(&server->clients, &send_data, server, client, msg);
    return (true);
}