/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** state header
*/

# ifndef _STATE_H
# define _STATE_H

typedef struct state_interface_s {
	void *state_item;
	void (*display_handler)(void *, ressource_t *, sfRenderWindow *);
	void (*event_handler)(game_t *);
	void (*del)(void *);
} state_interface_t;

typedef struct play_s {
	uint16_t current_map;
	uint64_t map_number;
	map_t **map;
	sprite_t *sprite;
	anim_t *anim;
} play_t;

//interface
state_interface_t *init_state_interface(void *, void (*)(state_interface_t *));
void del_state_interface(state_interface_t *);
//play
void load_map(lua_State *state, play_t *play);
play_t *init_play(char const *sprite_path, lua_State *state);
void display_handler_play(void *self, ressource_t *ressource,
	sfRenderWindow *window);
void event_handler_play(game_t *game);
void del_play(void *self);
void set_method_play(state_interface_t *state_interface);
// manager

#endif
