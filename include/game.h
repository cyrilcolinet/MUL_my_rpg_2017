/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** game header
*/

#ifndef _GAME_H
#define _GAME_H

typedef enum {
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

#endif