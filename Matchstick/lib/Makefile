##
## EPITECH PROJECT, 2018
## Makefile of Bootsrap my_printf
## File description:
## Makefile
##

SRC =	src/my_printf.c \
		src/function.c \
		src/function2.c \
		src/disp_stdarg.c \

OBJ =	${SRC:.c=.o}

NAME = libmy.a

CFLAGS = -W -Werror -Wextra -Wall

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	rm $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

test:
	gcc main.c -L. -lmy