/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server_receive
*/

#include <errno.h>
#include "ftp/server.h"

char *my_strcpy(char *dest, char *src, size_t dest_len) // TODO: move the function to the lib
{
    size_t src_len = 0;
    size_t index_src = 0;

    for (size_t i = 0; i < strlen(src); i++) {
        dest[dest_len + i] = src[i];
    }
    return (dest);
}

static command_t *concat_command(server_t *server, client_t *client, \
                                char *buf, ssize_t bytes_read)
{
    client->curr_command = realloc(client->curr_command, \
                (client->command_length + bytes_read + 1) * sizeof(char));
    client->curr_command = my_strcpy(client->curr_command, buf, \
                client->command_length);
    client->command_length += bytes_read;
    client->curr_command[client->command_length] = '\0';
    printf("Adding: %s\nSize: %ld\n", buf, client->command_length);
    free(buf);
    for (size_t i = 0; i < client->command_length - 1; i++) {
        if (client->curr_command[i] == '\r' && \
                                    client->curr_command[i + 1] == '\n') {
            return (command_create(server, client, client->curr_command));
        }
    }
    return (NULL);
}

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