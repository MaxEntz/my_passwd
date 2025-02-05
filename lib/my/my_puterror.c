/*
** EPITECH PROJECT, 2024
** B-PSU-100-MLH-1-1-mysudo-yann.toison-chabane
** File description:
** my_puterror.c
*/

#include "../../include/my_lib.h"

int my_puterror(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
    return 84;
}