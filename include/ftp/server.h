/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "queue/queue.h"
#include "command/command.h"

typedef struct client_s client_t;
typedef struct queue_s queue_t;
typedef struct command_s command_t;

typedef struct server_s {
    char *ip_address;
    size_t port;
    int fd;
    size_t max_connections;
    struct sockaddr_in socket;
    fd_set read_fds;
    fd_set write_fds;
    fd_set master_fds;
    int fd_max;
    bs_list_t *clients;
    queue_t *commands;
} server_t;

server_t *server_create(char *ip_address, size_t port, size_t max_connections);
bool server_start(server_t *server);
bool server_listen(server_t *server);
bool server_broadcast(server_t *server, client_t *client, char *msg);
bool server_send(server_t *server, client_t *client, char *msg);
command_t *server_receive(server_t *server, client_t *client);

#endif /* !SERVER_H_ */
