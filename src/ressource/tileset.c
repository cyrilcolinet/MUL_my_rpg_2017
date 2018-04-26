/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** tileset
*/

#include "rpg.h"

static void get_tileset_name(tileset_t *tileset, char const *path)
{
	uint64_t name_offset = cl_strchr(PATH_CHAR, path, cl_get_occurrence(PATH_CHAR, path)) + 1;

	for (uint64_t i = 0; i < TILESET_NAME_LEN; i++) {
		if (name_offset + 1 >= cl_strlen(path) || path[name_offset + 1] == EXT_CHAR)
			break;
		else
			tileset->name[i] = path[name_offset + i];
	}
}

tileset_t *init_tileset(char const *path)
{
	tileset_t *tileset = NULL;

	tileset = cl_calloc(sizeof(tileset_t));
	tileset->tileset.transform = sfTransform_Identity;
	tileset->tileset.blendMode = sfBlendNone;
	tileset->tileset.texture = sfTexture_createFromFile(path, NULL);
	tileset->height = sfTexture_getSize(tileset->tileset.texture).x;
	tileset->width = sfTexture_getSize(tileset->tileset.texture).y;
	get_tileset_name(tileset, path);
	free((void *)path);
	return tileset;
}

void del_tileset(void *self)
{
	tileset_t *_self = NULL;

	_self = (tileset_t *)self;
	sfTexture_destroy((sfTexture *)_self->tileset.texture);
	free(self);
}