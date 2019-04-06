/*
** BillyScene, 2018
** list_delete
** File description:
** bs_list_delete
*/

#include "my.h"

static hashmap_t *delete_first_element(hashmap_t **head)
{
    hashmap_t *tmp = NULL;

    if (head == NULL || *head == NULL)
        return (NULL);
    tmp = *head;
    *head = (*head)->next;
    return (tmp);
}

/**
 * @brief Delete an item of the list
 * 
 * @param head
 * @param id
 */
hashmap_t *hashmap_delete(hashmap_t **head, int id)
{
    hashmap_t *curr = NULL;
    hashmap_t *before_curr = NULL;

    if (id == 0)
        return (delete_first_element(head));
    curr = hashmap_get_by_id(head, id);
    before_curr = hashmap_get_by_id(head, id - 1);
    if (curr == NULL || before_curr == NULL)
        return (NULL);
    before_curr->next = curr->next;
    return (curr);
}