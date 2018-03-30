##
## EPITECH PROJECT, 2018
## lizz_overlay
## File description:
## lizz overlay library makefile
##

## Compilation variables

.PHONY				: 	all, clean, fclean, re

NAME 				= 	liblizz.a

TESTS 				= 	lizz_tests

SRCNAMES			= 	lizz.c 							\
						debugger/logger.c 				\
						utils/str_functions.c 			\
						managers/buttons_manager.c 		\
						managers/destroy_manager.c 		\
						managers/threads_manager.c 		\
						managers/clocks_manager.c 		\
						buttons/actions/btn_actions.c 	\
						buttons/btn_textures.c 			\
						buttons/btn_sprites.c 			\
						buttons/btn_general.c 			\
						threads/thread_general.c 		\
						clocks/clock_general.c

SRC 				= 	$(addprefix src/, $(SRCNAMES))

CFLAGS 				= 	-Wall -Wextra -I./include -g3

CC					= 	gcc

AR 					= 	ar rcs

CP 					= 	cp

RM 					= 	rm -rf

INCLUDE 			= 	./include

REMOTE_INCLUDE 		= 	../../include/lizz

INCLUDE_FILE		= 	*.h

LIB_OBJ 			= 	$(SRC:.c=.o)

all:				$(NAME)
					$(CP) $(NAME) ../$(NAME)
					mkdir -p $(REMOTE_INCLUDE)
					$(CP) $(INCLUDE)/$(INCLUDE_FILE) $(REMOTE_INCLUDE)

$(NAME):			$(LIB_OBJ)
					$(AR) $(NAME) $(LIB_OBJ)

clean:
					$(RM) $(LIB_OBJ)
					$(RM) $(TESTS)

fclean: 			clean
					$(RM) ../$(NAME)
					$(RM) $(NAME)
					$(RM) $(REMOTE_INCLUDE)

re: 				fclean all

tests:				re
					$(CC) $(CFLAGS) tests/*.c -lc_graph_prog -L../ -llizz -o $(TESTS)
