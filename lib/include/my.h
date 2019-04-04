/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

typedef struct bs_list_s
{
    int id;
    void *data;
    struct bs_list_s *next;
} bs_list_t;

/*    PROTOTYPES    */

/*    LIST    */
bs_list_t *bs_list_create(void *data);
bs_list_t *bs_list_delete(bs_list_t **head, int id);
bs_list_t *bs_list_get_by_id(bs_list_t **head, int id);
int bs_list_length(bs_list_t **head);
bs_list_t *bs_list_push(bs_list_t **head, void *data);
void bs_list_destroy(bs_list_t **head, void (*destroy)(bs_list_t *list));
bool bs_list_each(bs_list_t **head, \
bool (*func_each)(bs_list_t *element, va_list *args), ...);

/*    Numbers    */
bool my_is_nbr(char *str, bool can_be_negative);

#endif /* !MY_H_ */
