/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-secured-leo.gregori
** File description:
** table.c
*/
#include "secured.h"
#include "my.h"

int hash(char *key, int len)
{
    int res = 3;

    for (int i = 0; key[i] != '\0'; i++) {
        res = res * key[i];
        for (int j = 0; key[j] != '\0'; j++)
            res = res + key[i] * j * i * i + (j * j);
    }
    if (res < 0) {
        res = res * -1;
        res = res + 1;
    }
    return res;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    ht->len = len;
    ht->tab_list = malloc(len * sizeof(node_t *));
    return ht;
}

void delete_hashtable(hashtable_t *ht)
{
    node_t *current = NULL;
    node_t *temp = current;

    for (int i = 0; i < ht->len; i++) {
        current = ht->tab_list[i];
        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp->value);
            free(temp);
        }
    }
    free(ht->tab_list);
    free(ht);
}
