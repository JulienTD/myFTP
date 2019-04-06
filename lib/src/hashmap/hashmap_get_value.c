/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** hashmap_get_value
*/

#include <string.h>
#include "my.h"

void *hashmap_get_value(hashmap_t **head, char *key)
{
    hashmap_t *curr = NULL;

    if (head == NULL || *head == NULL)
        return (NULL);
    curr = *head;
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return (curr->value);
        }
        curr = curr->next;
    }
    return (NULL);
}