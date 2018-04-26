##
## EPITECH PROJECT, 2018
## lib my
## File description:
## Makefile
##

SRC_DIR		=	src/

SRC_EXTENTION	=	.c

SRC		=	cl_calloc		\
			cl_get_occurrence	\
			cl_is_in_str		\
			cl_str_cmp		\
			cl_strchr		\
			cl_strdup		\
			cl_strlen		\

SRC		:=	$(addprefix $(SRC_DIR), $(SRC))

SRC		:=	$(addsuffix $(SRC_EXTENTION), $(SRC))

INCLUDE		=	-I include

CC		=	gcc

FLAGS		=	-Wall -Wextra -Werror -std=c99

OBJ		=	$(SRC:.c=.o)

NAME		=	../libcl.a

.PHONY: $(NAME) clean

all:	$(NAME) clean
	cp -r include/ ../../

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