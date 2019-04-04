/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** command_destroy
*/

#include "command/command.h"

bool command_destroy(command_t *command)
{
    if (command == NULL)
        return (false);
    for (size_t i = 0; i < command->args_length; i++)
        free(command->args[i]);
    free(command->args);
    free(command);
    return (true);
}