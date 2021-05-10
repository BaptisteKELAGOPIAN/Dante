/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** create_maze
*/

#include "../include/my.h"

bool is_finished(dante_t *dante)
{
    for (int i = 1; i < dante->mazey - 1; i += 2) {
        for (int j = 1; j < dante->mazex - 1; j += 2) {
            if (dante->intmaze[i][j] != dante->intmaze[1][1]) {
                return false;
            }
        }
    }
    return true;
}

void ceil_fusion(dante_t *dante, int cell_1, int cell_2)
{
    for (int i = 1; i < dante->mazey - 1; i += 2) {
        for (int j = 1; j < dante->mazex - 1; j += 2) {
            if (dante->intmaze[i][j] == cell_2)
                dante->intmaze[i][j] = cell_1;
        }
    }
}

void continue_maze(dante_t *dante, int x, int y)
{
    int cell_1;
    int cell_2;
    if (dante->intmaze[y - 1][x] == -1) {
        cell_1 = dante->intmaze[y][x - 1];
        cell_2 = dante->intmaze[y][x + 1];
    }
    else {
        cell_1 = dante->intmaze[y - 1][x];
        cell_2 = dante->intmaze[y + 1][x];
    }
    if (cell_1 != cell_2) {
        dante->intmaze[y][x] = 0;
        ceil_fusion(dante, cell_1, cell_2);
    }
}

void make_maze(dante_t *dante)
{
    int x;
    int y = rand() % (dante->mazey - 2) + 1;

    if (y % 2 == 0)
        x = ((rand() % (dante->mazex - 2) / 2)) * 2 + 1;
    else
        x = ((rand() % (dante->mazex - 3) / 2)) * 2 + 2;
    continue_maze(dante, x, y);
}
