/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server_receive
*/

#include <errno.h>
#include "ftp/server.h"

static command_t *check_command_end(server_t *server, client_t *client)
{
    if (client->curr_command && strlen(client->curr_command) == 2 \
    && client->curr_command[0] == '\r' && client->curr_command[1] == '\n') {
        free(client->curr_command);
        client->command_length = 0;
        client->curr_command = NULL;
        return (NULL);
    }
    for (size_t i = 0; i < client->command_length - 1; i++) {
        if (client->curr_command[i] == '\r' && \
                                    client->curr_command[i + 1] == '\n') {
            return (command_create(server, client, client->curr_command));
        }
    }
    return (NULL);
}

static command_t *concat_command(server_t *server, client_t *client, \
                                char *buf, ssize_t bytes_read)
{
    client->curr_command = realloc(client->curr_command, \
                (client->command_length + bytes_read + 1) * sizeof(char));
    if (client->curr_command == NULL)
        return (NULL);
    client->curr_command = my_strcpy(client->curr_command, buf, \
                client->command_length);
    client->command_length += bytes_read;
    client->curr_command[client->command_length] = '\0';
    free(buf);
    return (check_command_end(server, client));
}

// TODO: Receive command, parse it, then return a list of commands
command_t *server_receive(server_t *server, client_t *client)
{
    char *buf = calloc(CMD_BUFFER_LENGTH, sizeof(char));
    ssize_t bytes_read = 0;

    if (server == NULL || client == NULL || buf == NULL)
        return (NULL);
    bytes_read = read(client->fd, buf, sizeof(buf));
    if (bytes_read == -1 && errno != EAGAIN) {
        return (concat_command(server, client, buf, CMD_BUFFER_LENGTH));
    } else if (bytes_read == 0) {
        client_disconnect(server, client);
        printf("[Server] Closing the socket %d\n", client->fd);
        free(buf);
        return (NULL);
    }
    if (bytes_read <= 0) {
        free(buf);
        return (NULL);
    }
    return (concat_command(server, client, buf, bytes_read));
}