/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** map
*/

#include "rpg.h"

map_t *init_map(char const *path)
{
	map_t *map = NULL;
	sfTexture *texture = NULL;

	map = cl_calloc(sizeof(map));
	map->map = sfSprite_create();
	texture = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(map->map, texture, sfFalse);
	return map;
}

void draw_map(void *self, sfRenderWindow *window)
{
	map_t *_self = NULL;

	_self = (map_t *)self;
	sfRenderWindow_drawSprite(window, _self->map, NULL);
}

void del_map(void *self)
{
	map_t *_self = NULL;

	_self = (map_t *)self;
	sfSprite_destroy(_self->map);
	free(_self);
}

void set_method_map(draw_interface_t *draw_interface)
{
	draw_interface->draw = &draw_map;
	draw_interface->del = &del_map;
}

// void draw_map(void *self, sfRenderWindow *window)
// {
// 	map_t *_self = NULL;
//
// 	_self = (map_t *)self;
// 	sfRenderWindow_drawPrimitives(window, _self->layer1, _self->height * _self->width, sfQuads, _self->tileset->tileset);
// 	sfRenderWindow_drawPrimitives(window, _self->layer2, _self->height * _self->width, sfQuads, _self->tileset->tileset);
// }