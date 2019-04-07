/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** queue
*/

#ifndef QUEUE_H_
    #define QUEUE_H_

#include "command/command.h"

typedef struct queue_s
{
    void *data;
    struct queue_s *next;
} queue_t;

bool queue_push(queue_t **head, void *data);
queue_t *queue_pop(queue_t **head);

#endif /* !QUEUE_H_ */
