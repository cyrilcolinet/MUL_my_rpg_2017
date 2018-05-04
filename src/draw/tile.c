/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** tile
*/

#include "rpg.h"

static sfVector2f tile_apply_pattern(sfVector2f vec, sfVector2f pattern,
	int64_t value)
{
	vec.x += pattern.x * value;
	vec.y += pattern.y * value;
	return vec;
}

tile_t init_tile(sfVector2f pos, sfVector2f tex)
{
	tile_t tile;
	sfVector2f position[4];
	sfVector2f tex_cords[4];
	sfVector2f pattern[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};

	for (uint8_t i = 0; i < 4; i++) {
		position[i] = tile_apply_pattern(pos, pattern[i], TILE_SIDE);
		tex_cords[i] = tile_apply_pattern(tex, pattern[i], TILE_SIDE);
	}
	for (uint8_t i = 0; i < 4; i++) {
		tile.tile[i].color = sfWhite;
		tile.tile[i].position = position[i];
		tile.tile[i].texCoords = tex_cords[i];
	}
	return tile;
}

void tile_append(tile_t tile, sfVertexArray *array)
{
	for (uint64_t i = 0; i < 4; i++)
		sfVertexArray_append(array, tile.tile[i]);
	sfVertexArray_setPrimitiveType(array, sfQuads);
}