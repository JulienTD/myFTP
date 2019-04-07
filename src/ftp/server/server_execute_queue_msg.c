/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** server_execute_queue
*/

#include "ftp/server.h"
#include "message/message.h"

static bool send_msg(queue_t *queue)
{
    message_t *msg = NULL;
    client_t *client = NULL;
    int char_wrote = 0;
    size_t char_to_write = 0;

    if (queue == NULL)
        return (false);
    msg = (message_t *)queue->data;
    client = msg->client;
    if (!FD_ISSET(client->fd, &msg->server->write_fds))
        return (false);
    char_to_write = strlen(msg->txt) - msg->index;
    char_wrote = write(client->fd, \
                        (char *)(msg->txt + msg->index), char_to_write);
    if (char_wrote != (int)strlen(msg->txt) && char_wrote != -1) {
        msg->index += char_wrote;
        return (false);
    }
    return (true);
}

bool server_execute_queue_msg(server_t *server)
{
    queue_t *queue = NULL;
    queue_t *queue_storage = NULL;

    if (server == NULL)
        return (false);
    queue = queue_pop(&server->msg_queue);
    while (queue) {
        if (send_msg(queue) == false)
            queue_push(&queue_storage, queue->data);
        queue = queue_pop(&server->msg_queue);
    }
    queue = queue_pop(&queue_storage);
    while (queue_storage) {
        if (queue->data)
            queue_push(&server->msg_queue, queue->data);
        queue = queue_pop(&queue_storage);
    }
    return (true);
}