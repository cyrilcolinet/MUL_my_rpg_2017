/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** map
*/

#include "rpg.h"
#include "map_layer.c"

map_t *init_map(char const *path, lua_State *state)
{
	map_t *map = NULL;
	uint64_t tileset_width = 0;

	map = cl_calloc(sizeof(map_t));
	load_table(state, path);
	goto_table_s(state, "tilesets");
	goto_table_n(state, 1);
	map->tileset = get_number_s(state, "name");
	tileset_width = get_number_s(state, "imagewidth");
	lua_pop(state, 2);
	map->height = get_number_s(state, "height");
	map->width = get_number_s(state, "width");
	for (uint8_t i = 0; i < 3; i++)
		map->layers[i] = generate_layer(tileset_width, i, state);
	map->hidden_layer = generate_hidden_layer(state);
	free((void *)path);
	return map;
}

void del_map(void *self)
{
	map_t *_self = NULL;

	_self = (map_t *)self;
	free(_self->hidden_layer);
	for (uint8_t i = 0; i < 3; i++)
		sfVertexArray_destroy(_self->layers[i]);
	free(_self);
}

void set_method_map(draw_interface_t *draw_interface)
{
	//draw_interface->draw = &draw_map;
	draw_interface->del = &del_map;
}

void draw_map(void *self, tileset_t **tileset, sfRenderWindow *window)
{
	map_t *_self = NULL;

	_self = (map_t *)self;
	for (uint8_t i = 0; i < 3; i++)
		sfRenderWindow_drawVertexArray(window, _self->layers[i],
			&tileset[_self->tileset]->tileset);
}