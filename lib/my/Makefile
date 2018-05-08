##
## EPITECH PROJECT, 2017
## libmy
## File description:
## Makefile libmy
##

## Compilation variables

.PHONY				: all, clean, fclean, re

NAME 				= libmy.a

SRCNAMES			= my_atoi.c 					\
					my_calloc.c 					\
					my_countwords.c 				\
					my_freetab.c 					\
					my_put_nbr.c 					\
					my_putchar.c 					\
					my_putstr.c 					\
					my_str_isnum.c 					\
					my_strcat.c 					\
					my_strcmp.c 					\
					my_strconfigure.c 				\
					my_strequ.c 					\
					my_strlen.c 					\
					my_strtok.c 					\
					my_strendswith.c 				\
					my_strjoin_char.c 				\
					my_strjoin_clear.c 				\
					my_strjoin.c 					\
					my_strdup.c 					\
					my_strcpy.c 					\
					my_strcat.c 					\
					my_strstartswith.c

SRC 				= $(addprefix src/, $(SRCNAMES))

CFLAGS 				= -Wall -Wextra -I./include

CC					= gcc

AR 					= ar rcs

CP 					= cp

RM 					= rm -f

INCLUDE 			= ./include

REMOTE_INCLUDE 		= ../../include/

INCLUDE_FILE		= my.h

LIB_OBJ 			= $(SRC:.c=.o)

all:				$(NAME)
					$(CP) $(NAME) ../$(NAME)
					$(CP) $(INCLUDE)/$(INCLUDE_FILE) $(REMOTE_INCLUDE)

$(NAME):			$(LIB_OBJ)
					$(AR) $(NAME) $(LIB_OBJ)

clean:
					$(RM) $(LIB_OBJ)

fclean: 			clean
					$(RM) ../$(NAME)
					$(RM) $(NAME)
					$(RM) $(REMOTE_INCLUDE)$(INCLUDE_FILE)

re: 				fclean all
