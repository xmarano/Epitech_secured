/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-secured-leo.gregori
** File description:
** secured.c
*/
#include "secured.h"

int hash(char *key, int len)
{
    int res = 3;

    for (int i = 0; key[i] != '\0'; i++) {
        res = res * key[i];
        for (int j = 0; key[j] != '\0'; j++)
            res = res + key[i] + j + i * i + (j * j) + 1;
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

    ht->tab_list = malloc(len * sizeof(node_t *));
    ht->len = len;
    return ht;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = hash(key, ht->len) % ht->len;
    node_t *new = malloc(sizeof(node_t));
    node_t *current = NULL;

    new->hashed = hash(key, ht->len);
    new->value = strdup(value);
    new->next = NULL;
    if (ht->tab_list[index] == NULL) {
        ht->tab_list[index] = new;
    } else {
        current = ht->tab_list[index];
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }
    return 0;
}

void ht_dump(hashtable_t *ht)
{
    node_t *current = NULL;

    for (int i = 0; i < ht->len; i++) {
        my_printf("[%d]:\n", i);
        current = ht->tab_list[i];
        while (current != NULL) {
            my_printf("> %d - %s \n", current->hashed, current->value);
            current = current->next;
        }
    }
}

void delete_hashtable(hashtable_t *ht)
{
    free(ht);
}
