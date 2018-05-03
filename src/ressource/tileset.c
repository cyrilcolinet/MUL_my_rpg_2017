/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** tileset
*/

#include "rpg.h"

tileset_t *init_tileset(char const *path)
{
	tileset_t *tileset = NULL;

	tileset = cl_calloc(sizeof(tileset_t));
	tileset->tileset.transform = sfTransform_Identity;
	tileset->tileset.blendMode = sfBlendNone;
	tileset->tileset.texture = sfTexture_createFromFile(path, NULL);
	tileset->height = sfTexture_getSize(tileset->tileset.texture).x;
	tileset->width = sfTexture_getSize(tileset->tileset.texture).y;
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