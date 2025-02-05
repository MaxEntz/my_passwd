/*
** EPITECH PROJECT, 2025
** my_passwd.c
** File description:
** It's the main file of my_passwd project
*/

#include "../include/my_passwd.h"

int my_passwd(int ac, char **av)
{
    if (ac == 2)
        return print_help();
    return main_passwd();
}
