/*
** EPITECH PROJECT, 2025
** hash_function.c
** File description:
** This file contains the hash function
*/

#include "../include/my_passwd.h"
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include <time.h>

static void generate_salt(char *salt, size_t length)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
        "GHIJKLMNOPQRSTUVWXYZ0123456789./";
    int index = 0;

    srand(time(NULL));
    for (size_t i = 0; i < length; i++) {
        index = rand() % (sizeof(charset) - 1);
        salt[i] = charset[index];
    }
    salt[length] = '\0';
}

char *hash_password(const char *password)
{
    char salt[3];
    char *hashed = NULL;

    generate_salt(salt, 2);
    hashed = crypt(password, salt);
    if (hashed == NULL) {
        fprintf(stderr, "crypt() failed\n");
        return NULL;
    }
    return strdup(hashed);
}

int verify_password(const char *password, const char *hash)
{
    char *computed_hash = crypt(password, hash);

    if (computed_hash == NULL) {
        return -1;
    }
    return (strcmp(computed_hash, hash) == 0);
}
