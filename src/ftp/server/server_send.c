/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server_send
*/

#include "ftp/client.h"
#include "ftp/server.h"
#include "queue/queue.h"
#include "message/message.h"

bool server_send(server_t *server, client_t *client, char *msg)
{
    message_t *message = NULL;

    if (server == NULL || client == NULL || msg == NULL)
        return (false);
    message = message_create(server, client, msg);
    if (message == NULL)
        return (false);
    queue_push(&server->msg_queue, message);
    return (true);
}