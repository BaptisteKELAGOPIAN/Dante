##
## EPITECH PROJECT, 2020
## Duo stumper
## File description:
## Makefile
##

CC	= gcc -O3

CFLAGS 	= -W -Wall -Wextra -g3
CFLAGS	+= -I ./include

SRC1	= $(wildcard generator/*.c) \

SRC2 	= $(wildcard solver/*.c) \

OBJ1 	= $(SRC1:.c=.o)

OBJ2 	= $(SRC2:.c=.o)

BIN1	= generator/generator

BIN2	= solver/solver

all: $(BIN1) $(BIN2)

$(BIN1): $(OBJ1)
	$(CC) $(OBJ1) -o $@

$(BIN2): $(OBJ2)
	$(CC) $(OBJ2) -o $@

clean:
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)

fclean:	clean
	$(RM) $(BIN1)
	$(RM) $(BIN2)

re: fclean all