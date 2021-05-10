/*
** EPITECH PROJECT, 2020
** my_h
** File description:
** my_h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<time.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_H_
#define MY_H_

typedef struct dante_s dante_t;

struct dante_s
{
    char **maze;
    int **intmaze;
    int mazex;
    int mazey;
    int maze_size;
    bool no_dead_end_so_far;
    bool rounded;
    int savey;
};

void print_maze(dante_t *maze);
void make_maze(dante_t *dante);
void print_edited_maze(dante_t *dante);
void create_grid(dante_t *dante);
int resolve(dante_t *dante);

bool is_finished(dante_t *dante);

void countxy(dante_t *dante);

void print(dante_t *dante);

void is_complex(dante_t *dante);

void copy(dante_t *dante);

char **my_str_to_word_array(char const *str);

char *buff(char *str);

#endif /* !MY_CD_H_ */