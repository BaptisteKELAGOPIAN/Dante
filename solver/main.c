/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** solve_maze
*/

#include "../include/my.h"

void browse_maze(dante_t *dante, int distance)
{
    int y = 1;
    int x = 0;
    distance++;
    while (distance > 0) {
        if (dante->intmaze[y - 1][x] == distance - 1)
            y--;
        if (dante->intmaze[y + 1][x] == distance - 1)
            y++;
        if (dante->intmaze[y][x - 1] == distance - 1)
            x--;
        if (dante->intmaze[y][x + 1] == distance - 1)
            x++;
        distance--;
        dante->intmaze[y][x] = -2;
    }
    dante->intmaze[1][0] = 1;
}

void reset_maze_values(dante_t *dante)
{
    for (int y = 0; y < dante->mazey; y++) {
        for (int x = 0; x < dante->mazex; x++) {
            if (dante->maze[y][x] == 'X')
                dante->maze[y][x] = -1;
            if (dante->maze[y][x] == '*')
                dante->maze[y][x] = 0;
        }
    }
    dante->maze[dante->mazey] = malloc(sizeof(int) * dante->mazex);

    for (int i = 0; i < dante->mazex; i++)
        dante->maze[dante->mazey][i] = -1;
}

void set_distance(dante_t *dante, int distance, int y, int x)
{
    if (dante->intmaze[y][x] == distance) {
        if (dante->intmaze[y - 1][x] == 0)
            dante->intmaze[y - 1][x] = distance + 1;
        if (dante->intmaze[y + 1][x] == 0)
            dante->intmaze[y + 1][x] = distance + 1;
        if (dante->intmaze[y][x - 1] == 0)
            dante->intmaze[y][x - 1] = distance + 1;
        if (dante->intmaze[y][x + 1] == 0)
            dante->intmaze[y][x + 1] = distance + 1;
        dante->no_dead_end_so_far = true;
    }
}

int resolve(dante_t *dante)
{
    int distance = 1;
    reset_maze_values(dante);
    dante->maze[dante->mazey - 1][dante->mazex - 1] = 1;
    copy(dante);
    dante->intmaze[dante->mazey - 1][dante->mazex - 1] = 1;
    while (dante->intmaze[1][0] == 0) {
        dante->no_dead_end_so_far = false;
        for (int y = dante->mazey - 1; y > 0; y--) {
            for (int x = dante->mazex- 1; x > 0; x--) {
                set_distance(dante, distance, y, x);
            }
        }
        if (!dante->no_dead_end_so_far)
            return 84;
        distance++;
    }
    dante->intmaze[1][0] = distance + 1;
    browse_maze(dante, distance);
    print(dante);
    return(0);
}

int main(int argc , char **argv)
{
    dante_t dante;

    if (argc != 2)
        return 84;
    dante.maze = my_str_to_word_array(buff(argv[1]));
    countxy(&dante);
    if (resolve(&dante) == 84)
        printf("no solution found\n");
    return 0;
}