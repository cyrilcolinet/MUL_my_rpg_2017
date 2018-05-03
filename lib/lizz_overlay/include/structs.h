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
struct 	thread_t;
struct 	clk_t;
struct 	sound_t;
struct 	btn_t;
struct	menu_t;
struct	lizz_t;

typedef struct pos_t {
	int 			x;
	int 			y;
} 	pos_t;

typedef struct thread_t {
	char 			*name;
	sfThread 		*thread;
	void 			(*callback)(void *);
	void 			(*destroy)(struct thread_t *);
	void 			(*start)(struct thread_t *);
	void 			(*wait)(struct thread_t *);
	void 			(*terminate)(struct thread_t *);
	struct thread_t	*next;
}	thread_t;

typedef struct clk_t {
	char 			*name;
	sfClock			*clock;
	void 			(*destroy)(struct clk_t *);
	void 			(*restart)(struct clk_t *);
	struct clk_t 	*next;
}	clk_t;

typedef struct sound_t {
	char 			*name;
	sfSound			*sound;
	struct sound_t 	*next;
}	sound_t;

typedef struct assets_t {
	char 			*name;
	menu_e 			belongsTo;
	bool			is_btn;
	sfSprite 		*sprite;
	sfTexture 		*texture;
	sfIntRect		*rect;
	sfIntRect		def_rect;
	sfVector2f		pos;
	void 			(*setTexture)(struct assets_t *, char *, sfIntRect *);
	void			(*setTextureRect)(struct assets_t *, sfIntRect *);
	void			(*setPosition)(struct assets_t *, int, int);
	void 			(*setRotation)(struct assets_t *, float);
	void 			(*destroy)(struct assets_t *);
	struct assets_t	*next;

}	assets_t;

typedef struct btn_t {
	char 			*name;
	menu_e 			belongsTo;
	assets_t		*asset;
	sfSprite 		*sprite;
	void 			(*create_asset)(struct btn_t *, struct lizz_t *);
	void			(*onHover)(struct btn_t *, int move);
	void			(*onClicked)(struct btn_t *, int move);
	void 			(*destroy)(struct btn_t *);
	struct btn_t 	*next;
} 	btn_t;

typedef struct lizz_t {
	assets_t 		*assets;
	btn_t	 		*btn;
	thread_t 		*thread;
	clk_t 			*clock;
}	lizz_t;

# endif