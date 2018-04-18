/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** sprite
*/

#include "rpg.h"

sprite_t *init_sprite(char const *path)
{
	sfTexture *texture = NULL;
	sprite_t *sprite = NULL;

	sprite = my_calloc(sizeof(sprite_t));
	sprite->direction = DOWN;
	sprite->state = STATIC_1;
	sprite->sprite = sfSprite_create();
	sprite->rect.left = 0;
	sprite->rect.top = sprite->direction * SPRITE_HEIGHT;
	sprite->rect.height = SPRITE_HEIGHT;
	sprite->rect.width = SPRITE_WIDTH;
	texture = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(sprite->sprite, texture, sfFalse);
	sfSprite_setTextureRect(sprite->sprite, sprite->rect);
	return sprite;
}

void draw_sprite(void *self, sfRenderWindow *window)
{
	sprite_t *_self = NULL;

	_self = (sprite_t *)self;
	sfRenderWindow_drawSprite(window, _self->sprite, NULL);
}

void del_sprite(void *self)
{
	sprite_t *_self = NULL;

	_self = (sprite_t *)self;
	sfTexture_destroy((sfTexture *)sfSprite_getTexture(_self->sprite));
	sfSprite_destroy(_self->sprite);
	free(_self);
}

void set_method_sprite(draw_interface_t *draw_interface)
{
	draw_interface->draw = &draw_sprite;
	draw_interface->del = &del_sprite;
}