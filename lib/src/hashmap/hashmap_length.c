/*
** BillyScene, 2018
** list_length
** File description:
** bs_list_length
*/

#include "my.h"

/**
 * @brief Returns the list length
 * 
 * @param head
 * @return int
 */
int hashmap_length(hashmap_t **head)
{
    hashmap_t *curr = NULL;
    int length = 0;

    if (head == NULL || *head == NULL)
        return (0);
    curr = *head;
    while (curr) {
        length++;
        curr = curr->next;
    }
    return (length);
}