/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server_start
*/

#include <string.h>
#include <stdbool.h>

#include "ftp/server.h"

bool server_start(server_t *server)
{
    int fd;
    int s_opt = 1;
    struct sockaddr_in servaddr;

    if (server == NULL)
        return (false);
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        printf("[Server] Error: failed to create the server socket !\n");
        return (false);
    }
    printf("[Server] The socket has been created\n");
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &s_opt, sizeof(int)) == -1) {
        printf("Error: failed to set the socket options !\n");
        return (false);
    }
    printf("[Server] The socket options have been set\n");
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(server->port);
    memset(&(servaddr.sin_zero), '\0', 8);
    if (bind(fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error: failed to bind !");
        return (false);
    }
    printf("[Server] The address and the port have been binded\n");
    if (listen(fd, server->max_connections) == -1) {
        printf("Error: failed to listen !");
        return (false);
    }
    printf("[Server] The server is now listening on %s:%ld\n", server->ip_address, server->port);
    FD_SET(fd, &server->master_fds);
    server->fd_max = fd;
    server->fd = fd;
    return (true);
}