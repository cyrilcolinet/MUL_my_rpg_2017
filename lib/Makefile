##
## EPITECH PROJECT, 2017
## my_library
## File description:
## Makefile for lib
##

all:		libmy.a liblizz.a

libmy.a:
			make -C ./my

liblizz.a:
			make -C ./lizz_overlay

clean:
			rm -f *.o

fclean:
			make fclean -C ./my
			make fclean -C ./lizz_overlay

re:			fclean all
