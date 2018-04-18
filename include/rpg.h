/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** RPG functions (header file)
*/

# ifndef RPG_H
# define RPG_H

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <SFML/Network.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include "my.h"
# include "struct.h"
# include "lizz/lizz.h"

# define ERROR_CODE 84
# define INTERFACE_PORT_REQ 9001
# define INTERFACE_PORT_REP 9002
// rpg.c
int 		main_rpg(int ac, char **av);

# endif
