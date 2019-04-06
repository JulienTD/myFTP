/*
** BillyScene, 2017
** list_each
** File description:
** bs_list_each
*/

#include <stdarg.h>
#include "my.h"

/**
 * @brief Calls a function for each element of list
 * 
 * @param head
 * @param func_each
 * @param ...
 */
bool hashmap_each(hashmap_t **head, \
bool (*func_each)(hashmap_t *element, va_list *args), ...)
{
    hashmap_t *curr = NULL;
    va_list args;
    va_list args_cpy;

    va_start(args, func_each);
    if (head == NULL || *head == NULL || func_each == NULL)
        return (false);
    curr = *head;
    while (curr) {
        if (func_each != NULL) {
            va_copy(args_cpy, args);
            func_each(curr, &args_cpy);
            va_end(args_cpy);
        }
        curr = curr->next;
    }
    va_end(args);
    return (true);
}
