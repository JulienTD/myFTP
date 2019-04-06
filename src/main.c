/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** main
*/

#include <stdio.h>
#include <string.h>

#include "ftp/client.h"
#include "ftp/server.h"
#include "my.h"

int main(int ac, char **av)
{
    if (ac == 2 && (strcmp(av[1], "-help") == 0 || \
                        strcmp(av[1], "-h") == 0)) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport  is the port number on which ");
        printf("the server socket listens\n");
        printf("\tpath  is the path to the home ");
        printf("directory for the Anonymous user\n");
        return (0);
    } else if (ac != 3) {
        printf("Wrong arguments.\n");
        printf("Please type ./myftp -help to have more informations.\n");
        return (84);
    }
    if (my_is_nbr(av[1], false) == false) {
        printf("Wrong arguments.\n");
        printf("Please type ./myftp -help to have more informations.\n");
        return (84);
    }
    server_t *server = server_create("127.0.0.1", atoi(av[1]), 20);

    if (server == NULL)
        return (84);
    server_configure(server);
    server_start(server);
    server_listen(server);
    return (0);
}