/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-baptiste.kelagopian
** File description:
** create_grid
*/

#include "../include/my.h"

void create_grid2(dante_t *dante) {
    int nb = 0;
    for (int y = 0; y < dante->mazey; y++) {
        for (int x = 0; x < dante->mazex; x++) {
            dante->intmaze[y][x] = -1;
        }
    }
    for (int i = 0; i < dante->mazey; i++) {
        for (int j = 0; j < dante->mazex; j++) {
            if (dante->maze[i][j] == 0) {
                nb++;
                dante->intmaze[i][j] = nb;
            }
        }
    }
    dante->intmaze[1][0] = 1;
    dante->intmaze[dante->mazey - 2][dante->mazex - 1] = nb;
    while (is_finished(dante) == false)
        make_maze(dante);
}

void create_grid(dante_t *dante)
{
    dante->maze = malloc(sizeof(int) * (dante->mazey*dante->mazex));
    dante->intmaze = malloc(sizeof(int) * (dante->mazey*dante->mazex));
    for (int i = 0; i < dante->mazey; i += 1) {
        dante->maze[i] = malloc(sizeof(int) * dante->mazex);
        dante->intmaze[i] = malloc(sizeof(int) * (dante->mazey*dante->mazex));
    }
    for (int y = 0; y < dante->mazey; y++) {
        for (int x = 0; x < dante->mazex; x++) {
            if (y % 2 == 0)
                dante->maze[y][x] = -1;
            else if (x % 2 == 0)
                dante->maze[y][x] = -1;
            else
                dante->maze[y][x] = 0;
        }
    }
    create_grid2(dante);
}

void is_complex(dante_t *dante)
{
    for (int i = 0; i < dante->mazey; i++) {
        int y = rand() % (dante->mazey - 2) + 1;
        int x = rand() % (dante->mazex - 2) + 1;
        dante->intmaze[x][y] = 0;
    }
}