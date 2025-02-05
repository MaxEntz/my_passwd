/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Will give the the difference of two pointer
*/

#include "../../include/my_lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int nb = 0;
    int lim = 0;

    if (my_strlen(s1) <= my_strlen(s2))
        lim = my_strlen(s1);
    if (my_strlen(s1) > my_strlen(s2))
        lim = my_strlen(s2);
    for (int i = 0; i <= lim; i++) {
        if (s1[i] == s2[i])
            continue;
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return nb;
}
