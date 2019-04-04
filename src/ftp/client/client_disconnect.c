/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** client_disconnect
*/

#include <stdbool.h>
#include "ftp/server.h"
#include "ftp/client.h"

bool client_disconnect(server_t *server, client_t *client)
{
    int id;
    int length;
    bs_list_t *list;

    if (server == NULL || client == NULL)
        return (false);
    FD_CLR(client->fd, &server->master_fds);
    close(client->fd);
    length = bs_list_length(&server->clients);
    for (id = 0; id < length; id++) {
        list = bs_list_get_by_id(&server->clients, id);
        if (list == NULL)
            continue;
        if (list->data == client)
            break;
    }
    bs_list_delete(&server->clients, id);
    return (true);
}