/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** solve_maze
*/

#include "../include/my.h"

void print_edited_maze(dante_t *dante)
{
    for (int y = 0; y < dante->mazey; y++) {
        for (int x = 0; x < dante->mazex; x++) {
            if (dante->maze[y][x] == -1)
                printf("[ ]");
            else
                printf("(%d)", dante->maze[y][x]);
        }
        printf("\n");
    }
}

void copy(dante_t *dante)
{
    dante->intmaze = malloc(sizeof(int) * (dante->mazey+1 * dante->mazex+1));
    for (int y = 0; y < dante->mazey +1 ; y++) {
        dante->intmaze[y] = malloc(sizeof(int) * dante->mazex+1);
    }
    for (int y = 0; y < dante->mazey; y++) {
        for (int x = 0; x < dante->mazex; x++) {
            dante->intmaze[y][x] = dante->maze[y][x];
        }
    }
}

void countxy(dante_t *dante)
{
    int y = 0;
    int x = 0;
    for (; dante->maze[y] != NULL; y++);
    for (; dante->maze[0][x]; x++);
    dante->mazey = y;
    dante->savey = y;
    dante->mazex = x;
}

void print(dante_t *dante)
{
    dante->intmaze[0][0] = -2;
    dante->intmaze[1][0] = -2;
    for (int y = 0; y < dante->savey; y++) {
        for (int x = 0; x < dante->mazex; x++) {
            if (dante->intmaze[y][x] == -1)
                printf("X");
            if (dante->intmaze[y][x] == -2)
                printf("o");
            if (dante->intmaze[y][x] >= 0)
                printf("*");
        }
        if (y < dante->mazey -1)
            printf("\n");
    }
}