/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-secured-leo.gregori
** File description:
** main.c
*/
#include "secured.h"

int hash(char *key, int len)
{
    int res = 1;

    for (int i = 0; key[i] != '\0'; i++) {
        res = res * key[i];
        for (int j = 0; key[j] != '\0'; j++)
            res = res + key[i] + j + i * i + (j * j);
    }
    if (res < 0)
        res = res * -1;
    return res % len;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    ht->len = len;
    ht->hash = hash;
    return ht;
}

void delete_hashtable(hashtable_t *ht)
{
    free(ht);
}

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 20);
    int i = 0;

    ht->arr = malloc(20 * sizeof(char *));
    while (i != 20) {
        ht->arr[i] = "ouais";
        i++;
    }
    ht->arr[i] = NULL;
    if (ht != NULL) {
        my_printf("hashtable created\n");
        my_printf("length: %d\n", ht->len);
    } else {
        write(2, "failed\n", 8);
        return 84;
    }
    delete_hashtable(ht);
    return 0;
}
