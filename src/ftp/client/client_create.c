/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** client_create
*/

#include <stdlib.h>
#include "ftp/client.h"

client_t *client_create(void)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return (NULL);
    client->fd = -1;
    client->addrlen = sizeof(client->addr);
    client->username = NULL;
    client->is_logged = false;
    client->curr_command = NULL;
    client->command_length = 0;
    return (client);
}