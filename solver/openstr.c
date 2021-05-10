/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** solve_maze
*/

#include "../include/my.h"

int is_alphanum(char c)
{
    if (c == '\0')
        return (0);
    if (c != '\n')
        return (1);
    else
        return (0);
}

int nb_words(char const *str)
{
    int i = 0;
    int word = 0;

    while (str[i] != '\0') {
        if (is_alphanum(str[i]) == 1)
            word++ ;
        while (is_alphanum(str[i]) == 1 && str[i] != '\0')
            i++ ;
        if (str[i] != '\0')
            i++ ;
    }
    return (word);
}

int taille(char const *str, int k)
{
    int t = 0;

    while (is_alphanum(str[k]) == 1) {
        k++ ;
        t++ ;
    }
    return (t);
}

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (nb_words(str) + 1));
    int i = 0;
    int a = 0;
    int l = 0;

    while (i != nb_words(str)) {
        a = 0;
        while (is_alphanum(str[l]) == 0)
            l++ ;
        array[i] = malloc(sizeof(char) * (taille(str, l) + 1));
        while (is_alphanum(str[l]) == 1) {
            array[i][a] = str[l];
            a++ ;
            l++ ;
        }
        array[i][a] = '\0';
        i++ ;
    }
    array[i] = NULL;
    return (array);
}

char *buff(char *str)
{
    char *buff;
    int fd;
    struct stat st;
    stat(str, &st);
    int size = st.st_size;
    buff = malloc(sizeof(char) * size);
    fd = open(str, O_RDONLY);
    if (fd <= 0)
        return (NULL);
    if (read(fd, buff,size) == -1) {
        free(buff);
        return (0);
    }
    return buff;
}
