##
## EPITECH PROJECT, 2018
## lizz_overlay
## File description:
## lizz overlay library makefile
##

## Compilation variables

.PHONY				: 	all, clean, fclean, re

NAME 				= 	liblizz.a

SRCNAMES			= 	lizz.c 							\
						debugger/logger.c 				\
						utils/str_functions.c

SRC 				= 	$(addprefix src/, $(SRCNAMES))

CFLAGS 				= 	-Wall -Wextra -I./include

CC					= 	gcc

AR 					= 	ar rcs

CP 					= 	cp

RM 					= 	rm -f

INCLUDE 			= 	./include

REMOTE_INCLUDE 		= 	../../include/lizz

INCLUDE_FILE		= 	my.h

LIB_OBJ 			= 	$(SRC:.c=.o)

all:				$(NAME)
					$(CP) $(NAME) ../$(NAME)
					mkdir -p $(REMOTE_INCLUDE)
					$(CP) $(INCLUDE)/$(INCLUDE_FILE) $(REMOTE_INCLUDE)

$(NAME):			$(LIB_OBJ)
					$(AR) $(NAME) $(LIB_OBJ)

clean:
					$(RM) $(LIB_OBJ)

fclean: 			clean
					$(RM) ../$(NAME)
					$(RM) $(NAME)
					$(RM) $(REMOTE_INCLUDE)

re: 				fclean all
