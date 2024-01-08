/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-secured-leo.gregori
** File description:
** main.c
*/
#include "secured.h"

int hash(char *mdp)
{
    int res = 1;

    for (int i = 0; mdp[i] != '\0'; i++) {
        res = res * mdp[i];
        for (int j = 0; mdp[j] != '\0'; j++)
            res = res + mdp[i] + j + i * i + (j * j);
    }
    if (res < 0)
        res = res * -1;
    return res;
}


int main(int argc, char **argv)
{
    my_printf("Vision : %d\n", hash("Vision"));
    my_printf("Perception : %d\n", hash("Perception"));
    my_printf("Fight : %d\n", hash("Fight"));
    my_printf("Pathfinding : %d\n", hash("Pathfinding"));
    return 0;
}
