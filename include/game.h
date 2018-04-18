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
} game_t;

//game
sfRenderWindow *init_window(void);
game_t *init_game(void);
void del_game(game_t *);

#endif