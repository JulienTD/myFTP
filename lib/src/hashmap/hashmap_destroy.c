/*
** BillyScene, 2018
** list_destroy
** File description:
** bs_list_destroy
*/

#include "my.h"

/**
 * @brief Destroys an hashmap with a custom function to destroy the data
 * 
 * @param head
 * @param destroy
 * @return true
 * @return false
 */
void hashmap_destroy(hashmap_t **head, void (*destroy)(hashmap_t *list))
{
    hashmap_t *curr = NULL;
    hashmap_t *tmp = NULL;

    if (head == NULL || *head == NULL)
        return;
    curr = *head;
    while (curr) {
        if (destroy != NULL) {
            destroy(curr);
            curr->value = NULL;
        }
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    *head = NULL;
}
