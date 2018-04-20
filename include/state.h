/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** state header
*/

#ifndef _STATE_H
#define _STATE_H

typedef struct {
	void *state_item;
	void (*display_handler)(void *, sfRenderWindow *);
	void (*event_handler)(game_t *);
	void (*del)(void *);
} state_interface_t;

typedef struct {
	map_t *map;
	sprite_t *sprite;
	anim_t *anim;
} play_t;

//interface
state_interface_t *init_state_interface(void *state_item, void (*set_method)(state_interface_t *state_interface));
void del_state_interface(state_interface_t *state_interface);
//play
play_t *init_play(char const *map_path, char const *sprite_path);
void display_handler_play(void *self, sfRenderWindow *window);
void event_handler_play(game_t *game);
void del_play(void *self);
void set_method_play(state_interface_t *state_interface);

#endif