/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-secured-leo.gregori
** File description:
** secured : secured.h
*/
#include "my.h"
#ifndef SECURED_H
    #define SECURED_H

struct node {
    int id;
    char *type;
    char *name;
    struct node *next;
};
struct secured {
    struct node *head;
};

#endif
