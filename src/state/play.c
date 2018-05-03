/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** state play
*/

#include "rpg.h"

void load_map(lua_State *state, play_t *play)
{
	char *base_path = NULL;
	char *ext = NULL;
	char *name = NULL;

	CHECK_DO(!load_table(state, MAP_DATA_PATH), return;)
	play->map_number = get_number_s(state, "number");
	play->map = cl_calloc(sizeof(map_t *) * (play->map_number + 1));
	base_path = get_string_s(state, "dir");
	ext = get_string_s(state, "ext");
	goto_table_s(state, "maps");
	for (uint64_t i = 1; i <= play->map_number; i++) {
		name = get_string_n(state, i);
		play->map[i - 1] = init_map(tricat(base_path, name, ext), state);
		free(name);
	}
	lua_pop(state, 2);
}

play_t *init_play(char const *sprite_path, lua_State *state)
{
	play_t *play = NULL;

	play = cl_calloc(sizeof(play_t));
	load_map(state, play);
	play->current_map = 0;
	play->sprite = init_sprite(sprite_path);
	play->anim = init_anim(play->sprite, 30, set_method_sprite_anim);
	return play;
}

void display_handler_play(void *self, ressource_t *ressource, sfRenderWindow *window)
{
	play_t *_self = NULL;

	_self = (play_t *)self;
	draw_map(_self->map[_self->current_map], ressource->tileset, window);
	draw_sprite(_self->sprite, window);
}

void event_handler_play(game_t *game)
{
	anim_t *anim = NULL;
	sfVector2f ku = {0, SPRITE_HEIGHT};

	anim = ((play_t *)game->state_list[game->state]->state_item)->anim;
	if (game->event.type == sfEvtKeyPressed && game->event.key.code == sfKeyDown) {
		if ((uint8_t)abs(game->tick - anim->time_0) >= anim->delay) {
			anim->anim(anim->anim_item);
			sfSprite_move(((sprite_t *)anim->anim_item)->sprite, ku);
		}
	}
}

void del_play(void *self)
{
	play_t *_self = NULL;

	_self = (play_t *)self;
	for (uint64_t i = 0; i < _self->map_number; i++)
		del_map(_self->map[i]);
	free(_self->map);
	del_sprite(_self->sprite);
	free(_self);
}

void set_method_play(state_interface_t *state_interface)
{
	state_interface->display_handler = &display_handler_play;
	state_interface->event_handler = &event_handler_play;
	state_interface->del = &del_play;
}