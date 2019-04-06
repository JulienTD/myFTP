/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char *src, size_t dest_len)
{
    for (size_t i = 0; i < strlen(src); i++) {
        dest[dest_len + i] = src[i];
    }
    return (dest);
}