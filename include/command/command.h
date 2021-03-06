/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** command
*/

#ifndef COMMAND_H_
    #define COMMAND_H_

#include "ftp/server.h"
#include "ftp/client.h"

typedef struct server_s server_t;
typedef struct client_s client_t;
typedef struct queue_s queue_t;

typedef struct command_s
{
    server_t *server;
    client_t *client;
    char **args;
    size_t args_length;
} command_t;

command_t *command_init(server_t *server, client_t *client);
command_t *command_create(server_t *server, client_t *client, char *raw_cmd);
bool command_destroy(command_t *command);
bool command_dispatch(queue_t *queue);

/*    Executors    */
bool user_command_executor(command_t *command);
bool pass_command_executor(command_t *command);

#endif /* !COMMAND_H_ */
