/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** my_is_nbr
*/

#include "my.h"

bool my_is_nbr(char *str, bool can_be_negative)
{
    size_t length = 0;

    if (str == NULL)
        return (false);
    length = strlen(str);
    for (size_t index = 0; index < length; index++) {
        if (str[index] == '-' && can_be_negative == false)
            return (false);
        if (str[index] < 48 || str[index] > 57)
            return(false);
    }
    return (true);
}