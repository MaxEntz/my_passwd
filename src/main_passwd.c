/*
** EPITECH PROJECT, 2025
** main_passwd.c
** File description:
** It's the main file of my_passwd
*/

#include "../include/my_passwd.h"

int main_passwd(void)
{
    char *passwd = malloc(sizeof(char) * 100);
    int choice = 0;
    int (*ptr[3])(void) = {&create_account, &log_in, &exit_choice};

    printf("(1) Create a account\t(2) Log in\t(3) Exit\nYour choice: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 3)
        return 84;
    if (ptr[choice - 1]() == 1)
        return 1;
    free(passwd);
    return 0;
}
