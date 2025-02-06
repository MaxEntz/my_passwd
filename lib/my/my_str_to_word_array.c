/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Will transform a str on word array
*/

#include <stdlib.h>
#include <stddef.h>
#include "../../include/my_passwd.h"
#include "../../include/my_lib.h"

int is_space(char c)
{
    if ((c == ' ' || c == '\t' || c == '\n' || c == '\v' ||
        c == '\f' || c == '\r'))
        return 1;
    return 0;
}

void take_word(char const *str, char **array, int w, int *i)
{
    int count = 0;
    int a = 0;
    int start = *i;

    for (; str[*i] != '\0' && !is_space(str[*i]); (*i)++)
        count++;
    array[w] = malloc(sizeof(char) * (count + 1));
    if (array[w] == NULL) {
        for (int j = 0; j < w; j++)
            free(array[j]);
        free(array);
        return;
    }
    while (start < *i) {
        array[w][a] = str[start];
        start++;
        a++;
    }
    array[w][a] = '\0';
}

int nb_word(char const *str)
{
    int check = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_space(str[i]) && check == 0) {
            check = 1;
            count++;
        }
        if (is_space(str[i])) {
            check = 0;
        }
    }
    return count;
}

char **my_str_to_word_array(char const *str, int len)
{
    char **word_array = malloc(sizeof(char *) * (nb_word(str) + 1));
    int w = 0;

    if (word_array == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        if (is_space(str[i]) == 0) {
            take_word(str, word_array, w, &i);
            w++;
        }
    }
    word_array[w] = NULL;
    return word_array;
}
