/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map layer
*/

static sfVertexArray *generate_layer(uint64_t tileset_width, uint8_t layer_id,
	lua_State *state)
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

static uint8_t *generate_hidden_layer(lua_State *state)
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