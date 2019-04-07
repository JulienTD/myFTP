/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** message_destroy
*/

#include <stdlib.h>
#include <string.h>
#include "message/message.h"

bool message_destroy(message_t *msg)
{
    if (msg == NULL)
        return (false);
    if (msg->txt)
        free(msg->txt);
    free(msg);
    return (true);
}