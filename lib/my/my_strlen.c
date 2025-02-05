/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** Will count and return the number of char in str
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int count = 0;

    if (str != NULL) {
        while (str[count] != '\0')
            count++;
    }
    return count;
}
