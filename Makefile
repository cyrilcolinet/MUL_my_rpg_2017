##
## EPITECH PROJECT, 2018
## PSU_tetris_2017
## File description:
## Makefile
##

CC		=	gcc

CFLAGS		=	-Wall -Wextra -std=c99

CFLAGS_TEST	=	--coverage

LDFLAGS		=	-l c_graph_prog -l python3.6m -L lib/ -lmy -llizz

LDFLAGS_TEST	=	-lcriterion -lgcov

NAME		=	my_rpg

SRC		=	src/main.c	\
			src/rpg.c	\


OBJ		=	$(SRC:.c=.o)

INCLUDE		=	-I include

TEST		=	tests/tests

SRC_TEST	=

OBJ_TEST	=	$(filter-out src/main.o, $(OBJ))	\
			$(SRC_TEST:.c=.o)			\

.PHONY:	all tests_run clean fclean lib

all:	$(NAME) clean

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)

fclean:	clean
	make -C lib fclean
	rm -f $(NAME)
	rm -f $(TEST)
	find -name '*.gc*' -delete
	find -name 'vgcore.*' -delete
	find -name '.gcov*' -delete

re: fclean all
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)

tests_run:	$(TEST) clean
	./$(TEST)

$(NAME):	lib obj
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

lib:
	make -C lib

obj:
	$(foreach src, $(SRC), $(CC) $(CFLAGS) -c $(src) $(INCLUDE) -o $(src:.c=.o);)

$(TEST):	lib obj_test
	$(CC) -o $(TEST) $(OBJ_TEST) $(LDFLAGS) $(LDFLAGS_TEST)

obj_test:
	$(foreach src, $(filter-out src/main.c, $(SRC)), $(CC) $(CFLAGS) $(CFLAGS_TEST) $(INCLUDE) -c $(src) -o $(src:.c=.o);)
	$(foreach src, $(SRC_TEST), $(CC) $(CFLAGS) $(INCLUDE) -c $(src) -o $(src:.c=.o);)

gcov:
	gcov -abcfu $(filter-out src/main.c, $(SRC))
