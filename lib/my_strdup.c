/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Infos
*/
#include "../my.h"
#include <unistd.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
