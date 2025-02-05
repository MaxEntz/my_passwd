/*
** EPITECH PROJECT, 2025
** graphical.h
** File description:
** Its the header file of graphical window
*/

#ifndef MY_PASSWD_H_
    #define MY_PASSWD_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

int my_passwd(int ac, char **av);
int main_passwd(void);
int print_help(void);
int exit_choice(void);
int log_in(void);
int create_account(void);
char *hash_password(const char *password);

#endif /* MY_PASSWD_H_ */
