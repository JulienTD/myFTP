/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** get_current_time
*/

#include <stdlib.h>
#include <time.h>

char *get_current_time(void)
{
    time_t timer;
    char *buffer = malloc(10 * sizeof(char));
    struct tm *tm_info;

    if (buffer == NULL)
        return (NULL);
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 10, "%H:%M:%S", tm_info);
    return (buffer);
}
