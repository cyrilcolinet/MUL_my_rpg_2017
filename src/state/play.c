/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** state play
*/

#include "rpg.h"

play_t *init_play(char const *map_path, char const *sprite_path)
{
	play_t *play = NULL;

	play = cl_calloc(sizeof(play_t));
	play->map = init_map(map_path);
	play->sprite = init_sprite(sprite_path);
	play->anim = init_anim(play->sprite, 30, set_method_sprite_anim);
	return play;
}

void display_handler_play(void *self, sfRenderWindow *window)
{
	play_t *_self = NULL;

	_self = (play_t *)self;
	draw_map(_self->map, window);
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
	(void)_self;
	// del_map(_self->map);
	// del_sprite(_self->sprite);
	// free(_self);
}

void set_method_play(state_interface_t *state_interface)
{
	state_interface->display_handler = &display_handler_play;
	state_interface->event_handler = &event_handler_play;
	state_interface->del = &del_play;
}