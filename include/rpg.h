/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** RPG functions (header file)
*/

# ifndef _RPG_H
# define _RPG_H

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

#ifndef lua_h
#include <lua.h>
#endif

# define ERROR_CODE 84

int 		main_rpg(int ac, char **av);

# endif
