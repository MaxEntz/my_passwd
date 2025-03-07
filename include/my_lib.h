/*
** EPITECH PROJECT, 2025
** my_passwd.h
** File description:
** Its the header file of my_passwd project
*/

#ifndef MY_LIB_H_
    #define MY_LIB_H_
    #include <unistd.h>
    #include <stdlib.h>

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
int my_putchar(char c);
int my_puterror(char *str);
char *my_str_concat(char *str1, char *str2);

#endif /* MY_LIB_H_ */
