/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** message
*/

#ifndef MESSAGE_H_
    #define MESSAGE_H_

#include "ftp/server.h"
#include "ftp/client.h"

typedef struct message_s
{
    char *txt;
    client_t *client;
    server_t *server;
    size_t index;
} message_t;

message_t *message_create(server_t *server, client_t *client, char *txt);
bool message_destroy(message_t *msg);

#endif /* !MESSAGE_H_ */
