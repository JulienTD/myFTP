/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** client_destroy
*/

#include <stdbool.h>
#include <stdlib.h>
#include "ftp/client.h"

bool client_destroy(client_t *client)
{
    if (client == NULL)
        return (false);
    close(client->fd);
    free(client);
    return (true);
}