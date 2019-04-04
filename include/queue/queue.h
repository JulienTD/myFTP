/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** queue
*/

#ifndef QUEUE_H_
    #define QUEUE_H_

#include "ftp/server.h"
#include "command/command.h"

typedef struct command_s command_t;
typedef struct server_s server_t;

typedef struct queue_s
{
    bs_list_t *element;
    int attempts;
    struct queue_s *next;
} queue_t;

bool queue_add_command(server_t *server, command_t *command);
bool queue_add_existing_queue(server_t *server, queue_t *queue);
queue_t *queue_retrieve_command(server_t *server);

#endif /* !QUEUE_H_ */
