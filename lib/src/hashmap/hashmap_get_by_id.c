/*
** BillyScene, 2018
** list_get_by_id
** File description:
** bs_list_get_by_id
*/

#include "my.h"

/**
 * @brief Get an item of the list by id
 * 
 * @param head
 * @param id
 */
hashmap_t *hashmap_get_by_id(hashmap_t **head, int id)
{
    hashmap_t *curr = NULL;

    if (head == NULL || *head == NULL)
        return (NULL);
    curr = *head;
    while (curr) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }
    return (NULL);
}