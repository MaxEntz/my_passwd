/*
** EPITECH PROJECT, 2025
** log_in.c
** File description:
** To log in on your account
*/

#include "../include/my_passwd.h"

int log_in(void)
{
    char *logname = malloc(sizeof(char) * 100);
    char *passwd = malloc(sizeof(char) * 100);

    scanf("Your logname: %s", logname);
    scanf("Your password: %s", passwd);
    free(logname);
    free(passwd);
    return 0;
}
