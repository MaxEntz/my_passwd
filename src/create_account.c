/*
** EPITECH PROJECT, 2025
** create_account.c
** File description:
** To create a account
*/

#include "../include/my_passwd.h"
#include "../include/my_lib.h"
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

static int verif_existing_account(char *logname, struct dirent *stat, DIR *dir)
{
    for (int i = 0; stat != NULL; i++) {
        if (strcmp(logname, stat->d_name) == 0) {
            my_putstr("The account already exist !\n");
            return main_passwd();
        }
        stat = readdir(dir);
    }
    return 128;
}

static int logname_take(char *logname, char *path,
    DIR *dir, struct dirent *stat)
{
    my_putstr("Your logname: ");
    scanf("%s", logname);
    dir = opendir(path);
    strcat(path, logname);
    if (dir == NULL) {
        closedir(dir);
        return 84;
    }
    stat = readdir(dir);
    if (verif_existing_account(logname, stat, dir) != 128)
        return 1;
    if (path == NULL || mkdir(path, 0700) == -1)
        return 84;
    return 0;
}

static int write_in_file(char *logname, char *passwd)
{
    char *path = strdup("./data/.ninja");
    FILE *file = fopen(path, "a");

    if (file == NULL)
        return 84;
    fprintf(file, "%s:%s:\n", logname, hash_password(passwd));
    fclose(file);
    return 0;
}

static int take_passwd(char *passwd_first, char *passwd_second, char *logname)
{
    my_putstr("Your password: ");
    scanf("%s", passwd_first);
    if (passwd_first == NULL)
        return 84;
    my_putstr("Retype your password: ");
    scanf("%s", passwd_second);
    if (strcmp(passwd_first, passwd_second) != 0) {
        my_putstr("The passwords are not the same !\n");
        return 84;
    }
    if (write_in_file(logname, passwd_first) == 84)
        return 84;
    return 0;
}

int create_account(void)
{
    char *passwd_first = malloc(sizeof(char) * 100);
    char *passwd_second = malloc(sizeof(char) * 100);
    char *logname = malloc(sizeof(char) * 100);
    char *path = strdup("./data/");
    DIR *dir;
    struct dirent *stat;

    if (logname_take(logname, path, dir, stat) == 1)
        return 0;
    if (take_passwd(passwd_first, passwd_second, logname) == 84)
        return 84;
    return 1;
}
