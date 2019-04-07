/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** message_create
*/

#include <stdlib.h>
#include <string.h>
#include "message/message.h"

message_t *message_create(server_t *server, client_t *client, char *txt)
{
    message_t *msg = NULL;

    if (txt == NULL)
        return (NULL);
    msg = malloc(sizeof(message_t));
    if (msg == NULL)
        return (NULL);
    msg->server = server;
    msg->client = client;
    msg->index = 0;
    msg->txt = calloc(strlen(txt) + 1, sizeof(char));
    if (msg->txt == NULL)
        return (NULL);
    msg->txt = strcpy(msg->txt, txt);
    return (msg);
}