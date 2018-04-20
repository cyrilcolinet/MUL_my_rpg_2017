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
	state_interface_t **state_list;
	game_state_t state;
	game_state_t prev;
	sfInt32 tick;
	sfClock *clock;
} game_t;

typedef struct {
	sfInt32 *tick;
	sfClock *clock;
} ll_t;

//game
sfRenderWindow *init_window(void);
game_t *init_game(void);
void del_game(game_t *);
void game_update_tick(void *data);

#endif