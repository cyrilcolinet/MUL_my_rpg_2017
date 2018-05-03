/*
** EPITECH PROJECT, 2018
** test_graph
** File description:
** map
*/

#include "rpg.h"

sfVertexArray *generate_layer(uint64_t tileset_width, uint8_t layer_id, lua_State *state)
{
	sfVertexArray *layer = NULL;
	uint64_t width = 0;
	uint64_t height = 0;
	sfVector2f tile[2] = {{0, 0}, {0, 0}};

	layer = sfVertexArray_create();
	goto_table_s(state, "layers");
	goto_table_n(state, layer_id + 1);
	width = get_number_s(state, "width");
	height = get_number_s(state, "height");
	goto_table_s(state, "data");
	for (uint64_t i = 1; i <= (width * height); i++) {
		tile[0].x = ceil((i - 1) / width);
 		tile[0].y = (i - 1) % width;
		tile[1].x = ceil(get_number_n(state, i) / tileset_width);
		tile[1].y = get_number_n(state, i) % tileset_width;
		tile_append(init_tile(tile[0], tile[1]), layer);
	}
	lua_pop(state, 3);
	return layer;
}

uint8_t *generate_hidden_layer(lua_State *state)
{
	uint8_t *layer = NULL;
	sfVector2u size = {0, 0};

	goto_table_s(state, "layers");
	goto_table_n(state, 4);
	size.x = get_number_s(state, "width");
	size.y = get_number_s(state, "height");
	layer = cl_calloc(sizeof(uint8_t) * size.x * size.y);
	goto_table_s(state, "data");
	for (uint64_t i = 1; i <= (size.x * size.y); i++)
		layer[i - 1] = get_number_n(state, i);
	lua_pop(state, 3);
	return layer;
}

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
		sfRenderWindow_drawVertexArray(window, _self->layers[i], &tileset[_self->tileset]->tileset);
}