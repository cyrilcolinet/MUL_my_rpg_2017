##
## EPITECH PROJECT, 2017
## libmy
## File description:
## Makefile libmy
##

## Compilation variables

SRC_DIR	=	src

SRC	=	my_atoi.c		\
		my_countwords.c 	\
		my_freetab.c 		\
		my_put_nbr.c 		\
		my_putchar.c 		\
		my_putstr.c 		\
		my_str_isnum.c 		\
		my_strcat.c 		\
		my_strcmp.c 		\
		my_strconfigure.c 	\
		my_strequ.c 		\
		my_strlen.c 		\
		my_strtok.c 		\
		my_strendswith.c 	\
		my_strjoin_char.c 	\
		my_strjoin_clear.c 	\
		my_strjoin.c 		\
		my_strdup.c 		\
		my_strcpy.c 		\
		my_strcat.c		\

SRC	:=	$(addprefix $(SRC_DIR)/, $(SRC))

INCLUDE	=	-I include

CC	=	gcc

FLAGS	=	-Wall -Wextra -Werror -std=c99

OBJ	=	$(SRC:.c=.o)

NAME	=	../libmy.a

.PHONY: $(NAME) clean

all:	$(NAME) clean
	cp include/my.h ../../include/

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

%.o:	%.c
	$(CC) $(FLAGS) -c $< $(INCLUDE) -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
	rm -f $(OBJ)
