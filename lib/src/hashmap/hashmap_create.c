/*
** BillyScene, 2018
** list_create
** File description:
** bs_list_create
*/

#include "my.h"

/**
 * @brief Create Hashmap
 * 
 * @param data
 * @param data_type
 */
hashmap_t *hashmap_create(char *key, void *value)
{
    hashmap_t *element = NULL;

    if (key == NULL)
        return (NULL);
    element = malloc(sizeof(hashmap_t));
    if (element == NULL)
        return (NULL);
    element->id = 0;
    element->key = calloc(strlen(key) + 1, sizeof(char));
    if (element->key == NULL)
        return (NULL);
    element->key = strcpy(element->key, key);
    element->value = value;
    element->next = NULL;
    return element;
}
