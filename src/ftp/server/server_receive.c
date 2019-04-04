/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server_receive
*/

#include <errno.h>
#include "ftp/server.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
char *my_strcpy(char *dest, char *src, size_t dest_len)
{
    size_t src_len = 0;
    size_t index_src = 0;

    for (size_t index = dest_len; index < src_len; index++) {
        dest[index] = src[index_src];
        index_src++;
    }
    return (dest);
}

char *my_concat(char **dest, char *src)
{
    int j = 0;

    if (src == NULL)
        return (*dest);
    if (dest == NULL || *dest == NULL) {
        *dest = calloc((strlen(src) + 1), sizeof(char));
    } else {
        *dest = realloc(*dest, (strlen(*dest) + strlen(src) + 1) * sizeof(char));
        for (int i = strlen(*dest); i < strlen(*dest) + strlen(src) + 1; i++)
            *dest[i] = '\0';
    }
    if (dest == NULL || *dest == NULL)
        return (NULL);
    j = strlen(*dest);
    for (int i = 0; src[i] != '\0'; i++, j++)
        *dest[j] = src[i];
    return (*dest);
}

// int main(void)
// {
//     char *str1 = NULL;
//     char *str2 = malloc(10 * sizeof(char));
//     str2[0] = 'a';
//     str2[1] = 'b';
//     str2[2] = 'c';
//     str2[3] = 'd';
//     str2[4] = '\0';
//     str1 = my_concat(&str1, str2);
//     printf("%s\n", str1);
//     return (0);
// }

static command_t *concat_command(server_t *server, client_t *client, char *buf, ssize_t bytes_read)
{
    printf("ITS HERE 2\n");
    client->curr_command = realloc(client->curr_command, (client->command_length + bytes_read + 1) * sizeof(char));
    client->curr_command = my_strcpy(client->curr_command, buf, client->command_length);
    client->command_length += bytes_read;
    client->curr_command[client->command_length] = '\0';
    // printf("Len1: %ld   Len2: %ld\n", strlen(client->curr_command), strlen(buf));
    // client->curr_command = strcat(client->curr_command, buf);
    printf("Adding: %s\nSize: %ld\nReal size: %ld\n", buf, client->command_length, 2);
    free(buf);
    // for (size_t i = 0; client->command_length != 0 && i < client->command_length - 1; i++) {
    //     // printf("%c - %d\n", client->curr_command[i], client->curr_command[i]);
    //     if (client->curr_command[i] == '\r' && client->curr_command[i + 1] == '\n') {
    //         // client->curr_command[i] = '\0';
    //         return (command_create(server, client, client->curr_command));
    //     }
    // }
    return (NULL);
}

command_t *server_receive(server_t *server, client_t *client)
{
    // char buf[CMD_BUFFER_LENGTH];
    char *buf = calloc(CMD_BUFFER_LENGTH, sizeof(char));
    ssize_t bytes_read = 0;

    if (server == NULL || client == NULL || buf == NULL)
        return (NULL);
    bytes_read = read(client->fd, buf, sizeof(buf));
    // buf[bytes_read] = '\0';
    if (bytes_read == -1 && errno != EAGAIN) {
        printf("ITS HERE 1\n");
        client->curr_command = realloc(client->curr_command, (client->command_length + CMD_BUFFER_LENGTH + 1) * sizeof(char));
        client->curr_command = my_strcpy(client->curr_command, buf, client->command_length);
        client->command_length += CMD_BUFFER_LENGTH;
        client->curr_command[client->command_length] = '\0';

        // client->curr_command = strcat(client->curr_command, buf);
        free(buf);
        return (NULL);
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