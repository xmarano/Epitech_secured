/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-secured-leo.gregori
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

typedef int (*hash_f)(char *, int);
typedef struct node {
    int hashed;
    char *value;
    struct node *next;
} node_t;

typedef struct {
    hash_f c_hash;
    int len;
    node_t **tab_list;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif /* HASHTABLE_H */
