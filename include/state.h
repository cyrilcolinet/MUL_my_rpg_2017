/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** state header
*/

# ifndef _STATE_H
# define _STATE_H

# include "rpg.h"

typedef struct {
	void 	*state_item;
	void 	(*display_handler)(void *, sfRenderWindow *);
	void 	(*event_handler)(game_t *);
	void 	(*del)(void *);
} state_interface_t;

typedef struct {
	uint16_t current_map;
	map_t 	**map;
	sprite_t *sprite;
	anim_t 	*anim;
} play_t;

//interface
state_interface_t *init_state_interface(void *, void (*)(state_interface_t *));
void 	del_state_interface(state_interface_t *);

//play
play_t 	*init_play(char const *, char const *);
void 	display_handler_play(void *, sfRenderWindow *);
void 	event_handler_play(game_t *);
void 	del_play(void *);
void 	set_method_play(state_interface_t *);

// manager
void 	init_main_state(game_t *);
void 	init_play_state(game_t *);
int		initialize_states(game_t *);

#endif
