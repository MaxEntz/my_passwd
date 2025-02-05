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
    my_putstr("\t./my_passwd\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmy_passwd will create a password management\n");
    return 0;
}
