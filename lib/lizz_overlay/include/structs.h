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
# include <SFML/System.h>

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>

# include "config.h"

struct	pos_t;
struct 	btn_t;

typedef struct pos_t {
	int 			rows;
	int 			columns;
} 	pos_t;

typedef struct thread_t {
	char 			*name;
	sfThread 		*thread;
	void 			*user_data;
	void 			(*callback)(void *);
	void 			(*destroy)(struct thread_t *);
	struct thread_t	*next;
}	thread_t;

typedef struct btn_t {
	char 			*name;
	menu_e 			belongsTo;
	sfSprite 		*sprite;
	sfTexture 		*texture;
	sfIntRect		*rect;
	sfIntRect		def_rect;
	pos_t 			current_pos;
	void 			(*setTexture)(struct btn_t *, char *, sfIntRect *);
	void			(*setTextureRect)(struct btn_t *, sfIntRect *);
	void			(*onHover)(struct btn_t *, int move);
	void			(*setPosition)(struct btn_t *, int, int);
	void 			(*destroy)(struct btn_t *);
	struct btn_t 	*next;
} 	btn_t;

typedef struct lizz_t {
	btn_t	 		*btn;
	thread_t 		*thread;
}	lizz_t;

# endif
