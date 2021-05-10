/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** main
*/

#include "../include/my.h"

static int is_num(char const c)
{
    if (c == '-' || c == '+')
        return (1);
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

int my_isnum(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!is_num(str[i]))
            return (0);
    return (1);
}

void print_maze(dante_t *dante)
{
    dante->maze[0][0] = -2;
    dante->maze[dante->mazey-1][dante->mazex-1] = -2;
    if (dante->rounded == true)
        dante->mazey--;
    for (int y = 0; y < dante->mazey; y++) {
        for (int x = 0; x < dante->mazex; x++) {
            if (dante->intmaze[y][x] == -1)
                printf("X");
            else
                printf("*");
        }
        if (y < dante->mazey -1)
            printf("\n");
    }
}

void addx(dante_t *dante)
{
    for (int y = 0; y < dante->mazey; y++) {
        for (int x = 0; x < dante->mazex; x++) {
            if (x == dante->mazex - 1)
                dante->intmaze[y][x] = -1;
        }
    }
    dante->intmaze[dante->mazey-2][dante->mazex-2] = -2;
    dante->intmaze[dante->mazey-2][dante->mazex-1] = -2;
    dante->intmaze[dante->mazey-1][dante->mazex-1] = -2;
    dante->intmaze[0][0] = -2;
}

int main(int ac, char **av)
{
    dante_t dante;
    dante.rounded = false;
    if (ac < 3 || ac > 4 || my_isnum(av[1]) == 0 || my_isnum(av[2]) == 0)
        return 84;
    dante.mazex = atoi(av[1]);
    dante.mazey = atoi(av[2]);
    if (dante.mazey % 2 == 0) {
        dante.mazey++;
        dante.rounded = true;
    }
    srand ( time(NULL) );
    create_grid(&dante);
    if (ac == 3)
        is_complex(&dante);
    else
        if (strcmp(av[3], "perfect") != 0)
            is_complex(&dante);
    addx(&dante);
    print_maze(&dante);
    return 0;
}