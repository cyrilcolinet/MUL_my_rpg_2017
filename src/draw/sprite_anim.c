/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** sprite anim
*/

#include "rpg.h"

void sprite_walk(void *self)
{
	sprite_t *_self = NULL;

	_self = self;
	_self->state = (_self->state + 1) % SPRITESHEET_WIDTH;
	_self->rect.left = _self->state * SPRITE_WIDTH;
	sfSprite_setTextureRect(_self->sprite, _self->rect);
}