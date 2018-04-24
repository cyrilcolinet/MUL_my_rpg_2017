/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** structs
*/

# ifndef RPG_STRUCTS_H
# define RPG_STRUCTS_H

# include "rpg.h"

typedef struct rpg_t {
	sfRenderWindow	*win;
	lizz_t			*lizz;
	menu_e			state;
}	rpg_t;

# endif
