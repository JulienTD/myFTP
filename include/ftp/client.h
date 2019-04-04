/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <stdbool.h>
#include "ftp/server.h"

#define CMD_BUFFER_LENGTH 128

typedef struct server_s server_t;

typedef struct client_s
{
    struct sockaddr_in addr;
    socklen_t addrlen;
    char *username;
    bool is_logged;
    int fd;
    char *curr_command;
    size_t command_length;
} client_t;

bool client_destroy(client_t *client);
client_t *client_create(void);
bool client_disconnect(server_t *server, client_t *client);

#endif /* !CLIENT_H_ */
