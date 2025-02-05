/*
** EPITECH PROJECT, 2025
** create_account.c
** File description:
** To create a account
*/

#include "../include/my_passwd.h"

int create_account(void)
{
    char *logname = malloc(sizeof(char) * 100);
    char *passwd = malloc(sizeof(char) * 100);

    scanf("Your logname: %s", logname);
    scanf("Your password: %s", passwd);
    free(logname);
    free(passwd);
    return 0;
}
