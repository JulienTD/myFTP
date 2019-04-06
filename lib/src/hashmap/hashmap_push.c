/*
** BillyScene, 2018
** list_push
** File description:
** bs_list_push
*/

#include "my.h"

/**
 * @brief Push data to then end of the list
 * 
 * @param head
 * @param data
 * @param data_type
 * @return bs_list_t*
 */
hashmap_t *hashmap_push(hashmap_t **head, char *key, void *value)
{
    hashmap_t *curr = NULL;
    hashmap_t *element = hashmap_create(key, value);

    if (element == NULL)
        return (NULL);
    if (head == NULL || *head == NULL) {
        *head = element;
        return (element);
    }
    curr = *head;
    while (curr->next) {
        curr = curr->next;
    }
    element->id = curr->id + 1;
    curr->next = element;
    return (element);
}