/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-secured-leo.gregori
** File description:
** secured.c
*/
#include "secured.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = 0;
    node_t *new = NULL;
    node_t *current = NULL;
    char *str = ht_search(ht, key);

    if (ht == NULL || ht->len <= 0 || key == NULL || value == NULL)
        return 84;
    if (my_strcmp(str, "error"))
        ht_delete(ht, key);
    index = ht->c_hash(key, ht->len) % ht->len;
    new = malloc(sizeof(node_t));
    new->hashed = ht->c_hash(key, ht->len);
    new->value = my_strdup(value);
    new->next = NULL;
    new->next = ht->tab_list[index];
    ht->tab_list[index] = new;
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index = 0;
    node_t *current = NULL;
    node_t *previous = NULL;

    if (ht == NULL || key == NULL || ht->len <= 0)
        return 84;
    index = ht->c_hash(key, ht->len) % ht->len;
    current = ht->tab_list[index];
    while (current != NULL && current->hashed != ht->c_hash(key, ht->len)) {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
        return 84;
    if (previous == NULL)
        ht->tab_list[index] = current->next;
    else
        previous->next = current->next;
    return 0;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int index = 0;
    node_t *current = NULL;
    char *error = "(null)";

    if (key == NULL || ht == NULL || ht->len <= 0)
        return NULL;
    index = ht->c_hash(key, ht->len) % ht->len;
    current = ht->tab_list[index];
    while (current != NULL && current->hashed != ht->c_hash(key, ht->len))
        current = current->next;
    if (current == NULL)
        return error;
    return current->value;
}

void ht_dump(hashtable_t *ht)
{
    node_t *current = NULL;

    if (ht == NULL || ht->len <= 0)
        return;
    for (int i = 0; i < ht->len; i++) {
        my_printf("[%d]:\n", i);
        current = ht->tab_list[i];
        while (current != NULL) {
            my_printf("> %d - %s\n", current->hashed, current->value);
            current = current->next;
        }
    }
}
