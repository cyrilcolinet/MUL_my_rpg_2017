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

struct	pos_t;
struct 	btn_t;

// buttons
typedef void (*btn_texture_t)(struct btn_t *, char *, sfIntRect *);
typedef void (*btn_texture_rect_t)(struct btn_t *, sfIntRect *);
typedef void (*btn_hover_t)(struct btn_t *, int move);
typedef void (*btn_position_t)(struct btn_t *, int, int);

typedef struct pos_t {
	int 				rows;
	int 				columns;
} 	pos_t;

typedef struct btn_t {
	char 				*name;
	menu_e 				belongsTo;
	sfSprite 			*sprite;
	sfTexture 			*texture;
	sfIntRect			*rect;
	sfIntRect			*def_rect;
	pos_t 				current_pos;
	btn_texture_t 		setTexture;
	btn_texture_rect_t	setTextureRect;
	btn_hover_t			onHover;
	btn_position_t		setPosition;
	struct btn_t 		*next;
} 	btn_t;

typedef struct lizz_t {
	btn_t	 			*btn;
}	lizz_t;

# endif
