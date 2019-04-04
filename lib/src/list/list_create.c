/*
** BillyScene, 2018
** list_create
** File description:
** bs_list_create
*/

#include "my.h"

/**
 * @brief Create List
 * 
 * @param data
 * @param data_type
 */
bs_list_t *bs_list_create(void *data)
{
    bs_list_t *element = malloc(sizeof(bs_list_t));

    if (element == NULL)
        return (NULL);
    element->id = 0;
    element->data = data;
    element->next = NULL;
    return element;
}
