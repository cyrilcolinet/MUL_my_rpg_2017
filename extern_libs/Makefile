##
## EPITECH PROJECT, 2018
## my_rpg_2017
## File description:
## extern_libs Makefile
##

NAME 	= 	../lib/libconfig.so

DIR	:=	$(CURDIR)/tmp

all:	$(NAME)

$(NAME):
	tar xvzf libconf.tar.gz
	cd libconfig && autoreconf -v
	cd libconfig && ./configure --prefix=$(DIR)
	make -C libconfig
	make install -C libconfig
	make check -C libconfig
	cp $(DIR)/lib/libconfig.so* ../lib/
	cp $(DIR)/include/libconfig.h ../include

clean:
	rm -rf ../lib/libconfig.so*
	rm -rf ../include/libconfig.h
	rm -rf libconfig

fclean: clean
	rm -rf $(DIR)

re: 	fclean all
