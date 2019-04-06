/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** ftpserver_listen
*/

#include <time.h>
#include "ftp/server.h"
#include "ftp/client.h"

static bool handler_client(bs_list_t *element, va_list *args)
{
    server_t *server = (server_t *)va_arg(*args, void *);
    client_t *client = (client_t *)element->data;
    command_t *command = NULL;

    if (!FD_ISSET(client->fd, &server->read_fds))
        return (true);
    // char buf[200];
    // ssize_t bytes_read;
    // bytes_read = read(client->fd, buf, sizeof(buf));
    // if (bytes_read == 0) {
    //     client_disconnect(server, client);
    //     printf("[Server] Closing the socket %d\n", client->fd);
    //     return (true);
    // }
    command = server_receive(server, client);
    if (command != NULL)
        queue_add_command(server, command);
    // analyse commands
    return (true);
}

static bool check_if_new_connection(server_t *server)
{
    client_t *client = NULL;

    if (FD_ISSET(server->fd, &server->read_fds)) {
        client = client_create();
        client->fd = accept(server->fd, (struct sockaddr *)&client->addr, &client->addrlen);
        if (client->fd == -1) {
            printf("[Server] Error: failed to acccept a connection !\n");
        } else {
            FD_SET(client->fd, &server->master_fds);
            FD_SET(client->fd, &server->write_fds);
            if (client->fd > server->fd_max)
                server->fd_max = client->fd;
            bs_list_push(&server->clients, client);
            printf("[Server] New connection from %s on socket %d\n", \
                inet_ntoa(client->addr.sin_addr), client->fd);
            server_send(server, client, "220 Service ready for new user.\r\n"); // TODO: added to the queue
        }
    }
    return (true);
}

bool server_listen(server_t *server)
{
    bool is_listening = true;
    int select_status = 0;

    while(is_listening){
        // nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
        server_execute_queue(server);
        server->read_fds = server->master_fds;
        server->write_fds = server->master_fds;
        select_status = select(server->fd_max + 1, \
            &server->read_fds, &server->write_fds, NULL, NULL); // FD_SET + 1
        if (select_status == -1) {
            printf("[Server] Error: failed to select !\n");
            return (false);
        }
        check_if_new_connection(server);
        bs_list_each(&server->clients, &handler_client, server);
    }
    return (true);
}
