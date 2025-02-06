/*
** EPITECH PROJECT, 2025
** log_in.c
** File description:
** To log in on your account
*/

#include "../include/my_passwd.h"
#include "../include/my_lib.h"
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

static int verif_existing_account(char *logname, struct dirent *stat, DIR *dir)
{
    for (int i = 0; stat != NULL; i++) {
        if (strcmp(logname, stat->d_name) == 0)
            return 1;
        stat = readdir(dir);
    }
    return 0;
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

static int free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return 1;
}

static char *find_hash(char *buffer, char *name)
{
    char **array = my_str_to_word_array(buffer, strlen(buffer));
    char *line = NULL;

    for (int i = 0; array[i] != NULL; i++) {
        if (strncmp(name, array[i], strlen(name)) == 0) {
            line = strtok(array[i], ":");
            line = strtok(NULL, ":");
            line = strdup(line);
            free_array(array);
            return line;
        }
    }
    free_array(array);
    return NULL;
}

static int verif_return(int fd, struct stat *sfile, char *buffer)
{
    if (fd == -1)
        return 1;
    if (read(fd, buffer, sfile->st_size) == -1)
        return 1;
    return 0;
}

char *find_password(char *logname)
{
    int fd = open("./data/.ninja", O_RDONLY);
    struct stat sfile;
    char *buffer = NULL;

    stat("./data/.ninja", &sfile);
    if (sfile.st_size < 3) {
        close(fd);
        return NULL;
    }
    buffer = malloc(sizeof(char) * (sfile.st_size + 1));
    if (verif_return(fd, &sfile, buffer))
        return NULL;
    buffer[sfile.st_size] = '\0';
    return find_hash(buffer, logname);
}

static int take_passwd(char *passwd_first, char *passwd_second, char *logname)
{
    my_putstr("Your password: ");
    scanf("%s", passwd_first);
    passwd_second = find_password(logname);
    if (passwd_first == NULL)
        return 84;
    if (passwd_second == NULL) {
        my_putstr("The logname doesn't exist !\n");
        return 84;
    }
    passwd_first = hash_password(passwd_first);
    printf("passwd_first: %s\n", passwd_first);
    printf("passwd_second: %s\n", passwd_second);
    if (strcmp(passwd_first, passwd_second) != 0) {
        my_putstr("The passwords are not the same !\n");
        return 84;
    }
    my_putstr("You are connected !\n");
    return 0;
}

int log_in(void)
{
    char *passwd_first = malloc(sizeof(char) * 100);
    char *passwd_second = malloc(sizeof(char) * 100);
    char *logname = malloc(sizeof(char) * 100);
    char *path = strdup("./data/");
    DIR *dir;
    struct dirent *stat;

    if (logname_take(logname, path, dir, stat) != 1)
        return 0;
    if (take_passwd(passwd_first, passwd_second, logname) == 84)
        return 84;
    return 1;
}
