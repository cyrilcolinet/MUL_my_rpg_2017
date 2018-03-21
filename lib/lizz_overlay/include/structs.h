/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** lizz overlay structs header file
*/

# ifndef LIZZ_OVERLAY_STRUCTS_H
# define LIZZ_OVERLAY_STRUCTS_H

# include <SFML/Audio.h>
# include <SFML/Config.h>
# include <SFML/Graphics.h>
# include <SFML/Network.h>
# include <SFML/OpenGL.h>
# include <SFML/System.h>
# include <SFML/Window.h>

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>

# include "config.h"

typedef struct btn_t {
	char 			*name;
	menu_e 			belongsTo;
	sfSprite 		*sprite;
	sfTexture 		*texture;
	void 			(*setTexture)(struct btn_t *, char *, sfIntRect *);
	struct btn_t *next;
} 	btn_t;

typedef struct lizz_t {
	btn_t	 		*btn;
}	lizz_t;

# endif
