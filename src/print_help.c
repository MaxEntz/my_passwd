/*
** EPITECH PROJECT, 2025
** print_help.c
** File description:
** It's only the help function
*/

#include "../include/my_passwd.h"
#include "../include/my_lib.h"

int print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_passwd [options] login\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    login    user login\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("    -h    print the help and exit\n");
    return 0;
}
