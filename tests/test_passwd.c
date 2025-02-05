/*
** EPITECH PROJECT, 2024
** my_passwd
** File description:
** Unit test for my_passwd
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../include/my_passwd.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Empty, Empty, .init = redirect_all_std)
{
    cr_assert_stdout_eq_str("EMPTY TEST\n");
}
