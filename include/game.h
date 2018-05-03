/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** game header
*/

# ifndef _GAME_H
# define _GAME_H

# undef WINDOW_HEIGHT
# define WINDOW_HEIGHT 1080

# undef WINDOW_WIDTH
# define WINDOW_WIDTH 1920

# undef WINDOW_TITLE
# define WINDOW_TITLE "my_rpg"

# undef WINDOW_STYLE
# define WINDOW_STYLE (sfClose)

# undef FRAMERATE
# define FRAMERATE 60

# undef NBR_STATES
# define NBR_STATES 1

# undef SMALLEST_KEY
# define SMALLEST_KEY sfKeyLeft

# undef BIGGEST_KEY
# define BIGGEST_KEY sfKeyDown

# include "rpg.h"

typedef enum {
	MAIN,
	PLAY
} game_state_t;

typedef struct game_s {
	sfRenderWindow *window;
	sfEvent event;
	ressource_t *ressource;
	state_interface_t **state_list;
	game_state_t state;
	game_state_t prev;
 	uint8_t tick;
	sfThread *game_clock;
} game_t;

//game
sfRenderWindow *init_window(void);
game_t *init_game(void);
void del_game(void *self);
void game_update_tick(void *data);

# endif
