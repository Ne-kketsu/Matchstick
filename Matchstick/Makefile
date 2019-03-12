##
## EPITECH PROJECT, 2019
## Makefile for Matchstick project
## File description:
## Makefile
##

SRC		=	main.c	\
			src/print_game_board.c	\
			src/function.c	\
			src/remove_sticks.c \
			src/get_p_move.c \
			src/check_win_or_loose.c \
			src/create_board.c \
			src/init_gameboard.c \
			src/check_input.c \
			src/check_input2.c \
			src/ia_move.c \

NAME	=	matchstick

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-W -Werror -Wextra -Wall -g3

CC = gcc

all:	mylib $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) -L src/lib/ -lmy

mylib : 
	make -C src/lib/

clean:
	rm $(NAME)
	rm $(OBJ)

fclean:	clean

re:	fclean all